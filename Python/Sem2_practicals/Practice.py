import random

# -------------------------------
# Distance Matrix (4 Cities)
# -------------------------------
dist = [
    [0, 10, 15, 20],
    [10, 0, 35, 25],
    [15, 35, 0, 30],
    [20, 25, 30, 0]
]

# -------------------------------
# Function to Calculate Tour Cost
# -------------------------------
def cost(route):
    total = 0
   
    # Distance between consecutive cities
    for i in range(len(route) - 1):
        total += dist[route[i]][route[i + 1]]
   
    # Add return distance to starting city
    total += dist[route[-1]][route[0]]
   
    return total


# -------------------------------
# Generate Neighbor (Swap Two Cities)
# -------------------------------
def neighbor(route):
    new_route = route[:]  # Copy route
   
    i, j = random.sample(range(len(route)), 2)
    new_route[i], new_route[j] = new_route[j], new_route[i]
    return new_route


# -------------------------------
# Hill Climbing Algorithm
# -------------------------------
route = list(range(4))
random.shuffle(route)
print("Initial Route:", route)
print("Initial Cost:", cost(route))

while True:
    new_route = neighbor(route)
   
    if cost(new_route) < cost(route):
        route = new_route
    else:
        break

print("\nBest Route Found:", route)
print("Minimum Cost:", cost(route))