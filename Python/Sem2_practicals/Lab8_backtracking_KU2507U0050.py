rules = [
    (["A", "B"], "C"),
    (["C"], "D")
]
facts = ["A", "B"]
def backward_chaining(goal):
    print(f"Trying to prove: {goal}")

    if goal in facts:
        print(f" -> '{goal}' is a known fact.")
        return True

    for conditions, result in rules:
        if result == goal:
            print(f" -> Checking rule: {conditions} -> {result}")

            if all(backward_chaining(cond) for cond in conditions):
                return True

    return False
if __name__ == "__main__":
    goal = "D"
    
    print("--- Starting Backward Chaining ---")
    if backward_chaining(goal):
        print(f"\nResult: Goal '{goal}' proved successfully!")
    else:
        print(f"\nResult: Goal '{goal}' cannot be proved.")