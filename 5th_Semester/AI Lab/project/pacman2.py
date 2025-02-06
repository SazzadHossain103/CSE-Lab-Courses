import pygame
import random
from collections import deque

# Initialize Pygame
pygame.init()

# Screen settings
WIDTH, HEIGHT = 600, 600
ROWS, COLS = 20, 20  # Grid size
CELL_SIZE = WIDTH // COLS
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("AI Hide and Seek - Enhanced")

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
BLUE = (0, 0, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
YELLOW = (255, 255, 0)

# Player and AI classes
class Player:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.score = 0  # Player's score

    def draw(self):
        pygame.draw.rect(screen, BLUE, (self.x * CELL_SIZE, self.y * CELL_SIZE, CELL_SIZE, CELL_SIZE))

    def move(self, dx, dy, walls):
        if (self.x + dx, self.y + dy) not in walls:
            self.x += dx
            self.y += dy

class Seeker:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.move_delay = 0  # Delay counter to slow down seeker movement

    def draw(self):
        pygame.draw.rect(screen, RED, (self.x * CELL_SIZE, self.y * CELL_SIZE, CELL_SIZE, CELL_SIZE))

    def bfs_search(self, player, walls):
        queue = deque([(self.x, self.y, [])])
        visited = set((self.x, self.y))

        while queue:
            cx, cy, path = queue.popleft()
            if (cx, cy) == (player.x, player.y):
                return path

            for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nx, ny = cx + dx, cy + dy
                if 0 <= nx < COLS and 0 <= ny < ROWS and (nx, ny) not in walls and (nx, ny) not in visited:
                    queue.append((nx, ny, path + [(nx, ny)]))
                    visited.add((nx, ny))

        return []

class PowerPoint:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def draw(self):
        pygame.draw.rect(screen, YELLOW, (self.x * CELL_SIZE, self.y * CELL_SIZE, CELL_SIZE, CELL_SIZE))

# Generate random walls for the maze
def generate_walls():
    walls = set()
    for _ in range(60):  # Number of walls
        x, y = random.randint(0, COLS - 1), random.randint(0, ROWS - 1)
        walls.add((x, y))
    return walls

# Generate Power Points at random locations
def generate_power_points(walls):
    power_points = []
    for _ in range(5):  # Number of Power Points
        while True:
            x, y = random.randint(0, COLS - 1), random.randint(0, ROWS - 1)
            if (x, y) not in walls:
                power_points.append(PowerPoint(x, y))
                break
    return power_points

# Main game loop
def main():
    player = Player(0, 0)
    seekers = [Seeker(COLS - 1, ROWS - 1), Seeker(COLS - 1, 0), Seeker(0, ROWS - 1)]  # Multiple seekers
    walls = generate_walls()
    power_points = generate_power_points(walls)
    clock = pygame.time.Clock()

    running = True
    while running:
        screen.fill(WHITE)

        # Draw grid
        for x in range(0, WIDTH, CELL_SIZE):
            pygame.draw.line(screen, BLACK, (x, 0), (x, HEIGHT))
        for y in range(0, HEIGHT, CELL_SIZE):
            pygame.draw.line(screen, BLACK, (0, y), (WIDTH, y))

        # Draw walls
        for (wx, wy) in walls:
            pygame.draw.rect(screen, BLACK, (wx * CELL_SIZE, wy * CELL_SIZE, CELL_SIZE, CELL_SIZE))

        # Draw player, seekers, and Power Points
        player.draw()
        for seeker in seekers:
            seeker.draw()
        for power_point in power_points:
            power_point.draw()

        # Event handling
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

            # Player movement with arrow keys
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    player.move(-1, 0, walls)
                elif event.key == pygame.K_RIGHT:
                    player.move(1, 0, walls)
                elif event.key == pygame.K_UP:
                    player.move(0, -1, walls)
                elif event.key == pygame.K_DOWN:
                    player.move(0, 1, walls)

        # AI seekers movement with delay
        for seeker in seekers:
            if seeker.move_delay == 0:  # Only move if delay counter is zero
                path = seeker.bfs_search(player, walls)
                if path:
                    seeker.x, seeker.y = path[0]  # Move seeker along the found path
                seeker.move_delay = 2  # Set delay to 2 frames
            else:
                seeker.move_delay -= 1  # Decrease delay counter each frame

        # Check if a seeker catches the player
        for seeker in seekers:
            if (seeker.x, seeker.y) == (player.x, player.y):
                font = pygame.font.SysFont(None, 60)
                text = font.render("Caught!", True, GREEN)
                screen.blit(text, (WIDTH // 3, HEIGHT // 3))
                pygame.display.update()
                pygame.time.delay(2000)
                running = False

        # Check if player collects a Power Point
        for power_point in power_points[:]:
            if (player.x, player.y) == (power_point.x, power_point.y):
                player.score += 10  # Increase score
                power_points.remove(power_point)

        # Display score
        font = pygame.font.SysFont(None, 36)
        score_text = font.render(f"Score: {player.score}", True, GREEN)
        screen.blit(score_text, (10, 10))

        pygame.display.update()
        clock.tick(10)  # Increase to 10 FPS to make the player feel faster

    pygame.quit()

# Run the game
main()