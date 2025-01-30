import subprocess
import random
import os
import time

# Vérifie si checker_linux existe
if not os.path.isfile("./checker_linux"):
    print("❌ Erreur: checker_linux n'existe pas dans ce répertoire.")
    print("👉 Assurez-vous qu'il est compilé et placé ici.")
    exit(1)

# Génère 100 permutations aléatoires uniques de [1,2,3,4,5]
test_cases = []
for _ in range(100):
    permutation = random.sample(range(1, 6), 5)
    test_cases.append(permutation)

# Ajoute des cas critiques spécifiques (optionnel)
edge_cases = [
    [1, 2, 3, 4, 5],  # Déjà trié
    [5, 4, 3, 2, 1],  # Inversé
    [2, 1, 3, 4, 5],  # Presque trié
]
test_cases += edge_cases

# Statistiques globales
total_tests = 0
total_operations = 0
successful_tests = 0
failed_tests = 0
timeout_tests = 0

def test_push_swap(numbers):
    global total_tests, total_operations, successful_tests, failed_tests, timeout_tests
    args = list(map(str, numbers))
    total_tests += 1

    try:
        # Mesure du temps d'exécution
        start_time = time.time()

        # Exécute push_swap
        process = subprocess.run(
            ["./push_swap"] + args,
            capture_output=True,
            text=True,
            timeout=5
        )
        operations = process.stdout.strip().splitlines()
        num_operations = len(operations)

        # Vérifie le tri avec checker_linux
        checker = subprocess.run(
            ["./checker_linux"] + args,
            input=process.stdout,
            capture_output=True,
            text=True,
            timeout=5
        )

        # Temps d'exécution
        execution_time = time.time() - start_time

        # Affichage des résultats détaillés
        print(f"🔍 Test #{total_tests}: {' '.join(args)}")
        print(f"➡️ Nombre d'opérations: {num_operations}")
        print(f"⏱️ Temps d'exécution: {execution_time:.3f} secondes")
        print(f"✅ Résultat: {checker.stdout.strip()}")
        print(f"🔄 Erreurs: {checker.stderr.strip()}")

        # Mise à jour des statistiques
        total_operations += num_operations
        if checker.stdout.strip() == "OK":
            successful_tests += 1
        else:
            failed_tests += 1
            print("❌ Erreur: La pile n'est pas triée correctement.")

        print()

    except subprocess.TimeoutExpired:
        timeout_tests += 1
        print(f"⏳ Timeout sur: {' '.join(args)}\n")

# Exécution des tests
print("🚀 Lancement de 100 tests aléatoires + cas critiques...\n")
for case in test_cases:
    test_push_swap(case)

# Affichage des statistiques globales
print("\n📊 Statistiques globales :")
print(f"✅ Tests réussis: {successful_tests} / {total_tests}")
print(f"❌ Tests échoués: {failed_tests} / {total_tests}")
print(f"⏳ Timeouts: {timeout_tests} / {total_tests}")
print(f"🔢 Nombre total d'opérations: {total_operations}")
print(f"📈 Moyenne d'opérations par test: {total_operations / total_tests:.1f}")