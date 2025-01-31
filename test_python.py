import itertools
import subprocess
import sys

def test_permutations():
    numbers = [1, 2, 3, 4, 5]
    total = 0
    success = 0
    failures = []
    max_ops = 0
    exceeding = []

    for perm in itertools.permutations(numbers):
        total += 1
        args = list(map(str, perm))
        
        # Exécuter push_swap
        try:
            push_swap = subprocess.check_output(['./push_swap'] + args, timeout=5)
            ops = push_swap.decode().strip().split('\n')
            ops = [op for op in ops if op]  # Ignorer les lignes vides
        except Exception as e:
            print(f"Erreur avec {perm}: {str(e)}")
            failures.append(perm)
            continue
        
        # Vérifier avec le checker
        try:
            checker = subprocess.Popen(
                ['./checker_linux'] + args,
                stdin=subprocess.PIPE,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE
            )
            out, err = checker.communicate(input=push_swap)
            
            if out.decode().strip() == "OK":
                success += 1
                if len(ops) > max_ops:
                    max_ops = len(ops)
                if len(ops) > 12:
                    exceeding.append(perm)
            else:
                failures.append(perm)
                print(f"Échec avec {perm} | Output: {out.decode().strip()}")
                
        except Exception as e:
            print(f"Erreur du checker avec {perm}: {str(e)}")
            failures.append(perm)
        
        # Afficher la progression
        sys.stdout.write(f"\rTestés: {total}/120 | OK: {success} | KO: {len(failures)}")
        sys.stdout.flush()

    # Rapport final
    print("\n\nRésultats finaux:")
    print(f"Tests réussis: {success}/120")
    print(f"Nombre maximum d'opérations: {max_ops}")
    print(f"Permutations avec +12 opérations: {len(exceeding)}")
    
    if failures:
        print("\nÉchecs:")
        for fail in failures:
            print(' '.join(map(str, fail)))

if __name__ == "__main__":
    test_permutations()