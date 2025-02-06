import pygame
import random
import sys

# Initialize pygame
pygame.init()

# Game settings
SCREEN_WIDTH = 600
SCREEN_HEIGHT = 400
GRID_SIZE = 20
FPS = 10

# Colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
YELLOW = (255, 255, 0)
RED = (255, 0, 0)
BLUE = (0, 0, 255)

# Screen setup
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Pac-Man Game")

# Load assets
font = pygame.font.Font(None, 36)

# Maze and game objects
class PacMan:
    def __init__(self):
        self.size = GRID_SIZE
        self.color = YELLOW
        self.x = GRID_SIZE
        self.y = GRID_SIZE
        self.direction = "RIGHT"
        self.score = 0

    def move(self):
        if self.direction == "UP":
            self.y -= GRID_SIZE
        elif self.direction == "DOWN":
            self.y += GRID_SIZE
        elif self.direction == "LEFT":
            self.x -= GRID_SIZE
        elif self.direction == "RIGHT":
            self.x += GRID_SIZE

        # Wrap around screen edges
        if self.x < 0:
            self.x = SCREEN_WIDTH - GRID_SIZE
        elif self.x >= SCREEN_WIDTH:
            self.x = 0
        elif self.y < 0:
            self.y = SCREEN_HEIGHT - GRID_SIZE
        elif self.y >= SCREEN_HEIGHT:
            self.y = 0

    def draw(self):
        pygame.draw.circle(screen, self.color, (self.x + GRID_SIZE // 2, self.y + GRID_SIZE // 2), GRID_SIZE // 2)

class Ghost:
    def __init__(self):
        self.size = GRID_SIZE
        self.color = RED
        self.x = random.randint(0, (SCREEN_WIDTH // GRID_SIZE) - 1) * GRID_SIZE
        self.y = random.randint(0, (SCREEN_HEIGHT // GRID_SIZE) - 1) * GRID_SIZE

    def move(self):
        directions = ["UP", "DOWN", "LEFT", "RIGHT"]
        move = random.choice(directions)
        if move == "UP":
            self.y -= GRID_SIZE
        elif move == "DOWN":
            self.y += GRID_SIZE
        elif move == "LEFT":
            self.x -= GRID_SIZE
        elif move == "RIGHT":
            self.x += GRID_SIZE

        # Wrap around screen edges
        if self.x < 0:
            self.x = SCREEN_WIDTH - GRID_SIZE
        elif self.x >= SCREEN_WIDTH:
            self.x = 0
        elif self.y < 0:
            self.y = SCREEN_HEIGHT - GRID_SIZE
        elif self.y >= SCREEN_HEIGHT:
            self.y = 0

    def draw(self):
        pygame.draw.rect(screen, self.color, (self.x, self.y, GRID_SIZE, GRID_SIZE))

class Dot:
    def __init__(self, x, y):
        self.size = GRID_SIZE // 4
        self.color = WHITE
        self.x = x
        self.y = y

    def draw(self):
        pygame.draw.circle(screen, self.color, (self.x + GRID_SIZE // 2, self.y + GRID_SIZE // 2), self.size)

# Game setup
pacman = PacMan()
ghosts = [Ghost() for _ in range(4)]
dots = [Dot(x, y) for x in range(0, SCREEN_WIDTH, GRID_SIZE) for y in range(0, SCREEN_HEIGHT, GRID_SIZE)]

clock = pygame.time.Clock()

# Game loop
running = True
while running:
    screen.fill(BLACK)

    # Event handling
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP:
                pacman.direction = "UP"
            elif event.key == pygame.K_DOWN:
                pacman.direction = "DOWN"
            elif event.key == pygame.K_LEFT:
                pacman.direction = "LEFT"
            elif event.key == pygame.K_RIGHT:
                pacman.direction = "RIGHT"

    # Move pacman and ghosts
    pacman.move()
    for ghost in ghosts:
        ghost.move()

    # Check for collisions with dots
    pacman_rect = pygame.Rect(pacman.x, pacman.y, GRID_SIZE, GRID_SIZE)
    for dot in dots[:]:
        dot_rect = pygame.Rect(dot.x, dot.y, GRID_SIZE, GRID_SIZE)
        if pacman_rect.colliderect(dot_rect):
            dots.remove(dot)
            pacman.score += 1

    # Check for collisions with ghosts
    for ghost in ghosts:
        ghost_rect = pygame.Rect(ghost.x, ghost.y, GRID_SIZE, GRID_SIZE)
        if pacman_rect.colliderect(ghost_rect):
            running = False

    # Draw everything
    pacman.draw()
    for ghost in ghosts:
        ghost.draw()
    for dot in dots:
        dot.draw()

    # Display score
    score_text = font.render(f"Score: {pacman.score}", True, WHITE)
    screen.blit(score_text, (10, 10))

    pygame.display.flip()
    clock.tick(FPS)

pygame.quit()
sys.exit()
