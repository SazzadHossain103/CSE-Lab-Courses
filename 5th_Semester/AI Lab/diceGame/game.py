import random
import tkinter as tk
from tkinter import messagebox
from PIL import Image, ImageTk  # For handling images in tkinter

class DiceGame:
    def __init__(self, root):
        self.root = root
        self.root.title("Dice Game")
        
        # Game variables
        self.player_scores = [0, 0]  # Player 1 and Player 2 scores
        self.current_player = 0  # Start with Player 1 (index 0)
        
        # GUI elements
        self.info_label = tk.Label(root, text="Welcome to the Dice Game!", font=("Arial", 16))
        self.info_label.pack(pady=10)
        
        self.score_label = tk.Label(root, text="Scores: Player 1 - 0 | Player 2 - 0", font=("Arial", 14))
        self.score_label.pack(pady=10)
        
        self.dice_result_label = tk.Label(root, text="Roll the dice to start!", font=("Arial", 14))
        self.dice_result_label.pack(pady=10)

        # Dice image
        self.dice_image_label = tk.Label(root)
        self.dice_image_label.pack(pady=10)
        
        self.roll_button = tk.Button(root, text="Roll Dice", font=("Arial", 14), command=self.roll_dice)
        self.roll_button.pack(pady=20)
        
        # Load dice images
        self.dice_images = [ImageTk.PhotoImage(Image.open(f"dice{i}.png").resize((100, 100))) for i in range(1, 7)]
    
    def roll_dice(self):
        dice = random.randint(1, 6)
        self.dice_image_label.config(image=self.dice_images[dice - 1])  # Display dice image
        self.dice_result_label.config(text=f"Player {self.current_player + 1} rolled a {dice}!")
        
        if dice == 1:
            self.player_scores[self.current_player] = 0
            self.info_label.config(text=f"Player {self.current_player + 1}'s score reset to 0!")
        elif dice == 6:
            opponent = 1 - self.current_player
            self.player_scores[opponent] = max(0, self.player_scores[opponent] - 6)
            self.info_label.config(text=f"Player {self.current_player + 1} decreased Player {opponent + 1}'s score by 6!")
        else:
            self.player_scores[self.current_player] += dice
            self.info_label.config(text=f"Player {self.current_player + 1}'s score increased by {dice}.")
        
        # Update scores on screen
        self.score_label.config(text=f"Scores: Player 1 - {self.player_scores[0]} | Player 2 - {self.player_scores[1]}")
        
        # Check for winner
        if self.player_scores[self.current_player] >= 50:
            messagebox.showinfo("Game Over", f"Player {self.current_player + 1} wins with {self.player_scores[self.current_player]} points!")
            self.reset_game()
            return
        
        # Switch player turn
        self.current_player = 1 - self.current_player
        self.info_label.config(text=f"Player {self.current_player + 1}'s turn!")
    
    def reset_game(self):
        """Reset the game to start over."""
        self.player_scores = [0, 0]
        self.current_player = 0
        self.info_label.config(text="Welcome to the Dice Game!")
        self.score_label.config(text="Scores: Player 1 - 0 | Player 2 - 0")
        self.dice_result_label.config(text="Roll the dice to start!")
        self.dice_image_label.config(image="")  # Clear the dice image

# Create the Tkinter window
root = tk.Tk()
game = DiceGame(root)
root.mainloop()
