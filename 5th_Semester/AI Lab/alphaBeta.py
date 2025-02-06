


def alpha_beta_pruning(node, depth, alpha, beta, maximizing_player):
    # Terminal node condition
    if depth == 0 or isinstance(node, int):
        return node

    if maximizing_player:
        max_eval = float('-inf')
        for child in node:
            eval = alpha_beta_pruning(child, depth - 1, alpha, beta, False)
            max_eval = max(max_eval, eval)
            alpha = max(alpha, eval)
            if beta <= alpha:
                break  # Beta cut-off
        return max_eval
    else:
        min_eval = float('inf')
        for child in node:
            eval = alpha_beta_pruning(child, depth - 1, alpha, beta, True)
            min_eval = min(min_eval, eval)
            beta = min(beta, eval)
            if beta <= alpha:
                break  # Alpha cut-off
        return min_eval


# Define the game tree (nested lists represent children)
game_tree = [
    [  # Node B (Min)
        [2, 3],  # Node D (Max)
        [5, 9]   # Node E (Max)
    ],
    [  # Node C (Min)
        [0, 1],  # Node F (Max)
        [7, 5]   # Node G (Max)
    ]
]

# Start the alpha-beta pruning from the root node (A)
root_value = alpha_beta_pruning(game_tree, depth=3, alpha=float('-inf'), beta=float('inf'), maximizing_player=True)
print("The root value is:", root_value)

