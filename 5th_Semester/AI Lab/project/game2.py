import pygame
import random

# Initialize Pygame
pygame.init()

# Game settings
width, height = 500, 600
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Obstacle Avoidance Game with Increasing Difficulty") #game title

# Define colors
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
YELLOW = (255, 255, 0)
BLACK = (0, 0, 0)

# Define player attributes
player_width, player_height = 50, 50
player_x, player_y = width // 2 - player_width // 2, height - player_height - 10
player_speed = 5
lives = 3  # Player starts with 3 lives

# Define obstacle attributes
obstacle_width, obstacle_height = 50, 50
obstacle_speed = 5
obstacles = []
obstacle_count = 0  # Track how many obstacles have been created
obstacle_spawn_rate = 3  # Initial rate of obstacle appearance (1 out of 100 chance per frame)
min_obstacle_gap = 60  # Minimum gap to avoid overlapping obstacles

# Define coin attributes
coin_width, coin_height = 40, 40
coin = None  # Initially, no coin exists

# Define the clock
clock = pygame.time.Clock()

# Font for displaying lives and other info
font = pygame.font.SysFont(None, 36)

def is_overlapping(x1, y1, w1, h1, x2, y2, w2, h2):
    """Check if two rectangles are overlapping"""
    return not (x1 + w1 < x2 or x1 > x2 + w2 or y1 + h1 < y2 or y1 > y2 + h2)

def create_obstacle():
    """Create a new obstacle at a random x position, avoiding overlap with existing obstacles and coin"""
    global obstacle_count
    max_attempts = 20  # Limit the number of attempts to find a non-overlapping position
    for _ in range(max_attempts):
        x_pos = random.randint(0, width - obstacle_width)
        y_pos = -obstacle_height
        
        # Check for overlap with existing obstacles
        overlap = False
        for obstacle in obstacles:
            if is_overlapping(x_pos, y_pos, obstacle_width, obstacle_height,
                              obstacle[0], obstacle[1], obstacle_width, obstacle_height):
                overlap = True
                break
        
        # Check for overlap with the current coin position
        if coin and is_overlapping(x_pos, y_pos, obstacle_width, obstacle_height,
                                   coin[0], coin[1], coin_width, coin_height):
            overlap = True
        
        if not overlap:
            obstacles.append([x_pos, y_pos])
            break
    
    # Increment obstacle count and check if a coin should appear
    obstacle_count += 1
    if obstacle_count % 30 == 0:  # Every 30 obstacles, create a coin
        create_coin()

def move_obstacles():
    """Move obstacles down the screen"""
    for obstacle in obstacles:
        obstacle[1] += obstacle_speed
    # Remove obstacles that have passed off the screen
    obstacles[:] = [obstacle for obstacle in obstacles if obstacle[1] < height]

def create_coin():
    """Create a coin at a random position at the top of the screen, avoiding overlap with obstacles"""
    global coin
    max_attempts = 20  # Limit the number of attempts to find a non-overlapping position
    for _ in range(max_attempts):
        x_pos = random.randint(0, width - coin_width)
        y_pos = -coin_height
        
        # Check for overlap with existing obstacles
        overlap = False
        for obstacle in obstacles:
            if is_overlapping(x_pos, y_pos, coin_width, coin_height,
                              obstacle[0], obstacle[1], obstacle_width, obstacle_height):
                overlap = True
                break
        
        if not overlap:
            coin = [x_pos, y_pos]
            break

def move_coin():
    """Move the coin down the screen"""
    if coin:
        coin[1] += obstacle_speed
        # Remove the coin if it goes off the screen
        if coin[1] >= height:
            return None
    return coin

def check_collision():
    """Check for collision between player and any obstacles"""
    global player_x, player_y, lives
    for obstacle in obstacles:
        if (player_x + player_width > obstacle[0] and player_x < obstacle[0] + obstacle_width and
            player_y + player_height > obstacle[1] and player_y < obstacle[1] + obstacle_height):
            return True
    return False

def check_coin_collection():
    """Check if the player collects the coin"""
    global player_x, player_y, coin, lives, obstacle_spawn_rate, obstacle_speed
    if coin:
        if (player_x + player_width > coin[0] and player_x < coin[0] + coin_width and
            player_y + player_height > coin[1] and player_y < coin[1] + coin_height):
            lives += 1  # Gain an extra life
            coin = None  # Remove the coin after collection
            
            # Increase the difficulty by increasing the obstacle spawn rate and speed
            if obstacle_spawn_rate < 10:  # Limit the maximum spawn rate
                obstacle_spawn_rate += 1
                obstacle_speed += 1  # Increase obstacle speed each time difficulty level increases

def draw():
    """Draw all game elements on the screen"""
    screen.fill(BLACK)
    
    # Draw player
    pygame.draw.rect(screen, GREEN, (player_x, player_y, player_width, player_height))
    
    # Draw obstacles
    for obstacle in obstacles:
        pygame.draw.rect(screen, RED, (obstacle[0], obstacle[1], obstacle_width, obstacle_height))
    
    # Draw coin if it exists
    if coin:
        pygame.draw.rect(screen, YELLOW, (coin[0], coin[1], coin_width, coin_height))
    
    # Display lives
    lives_text = font.render(f'Lives: {lives}', True, WHITE)
    screen.blit(lives_text, (10, 10))
    
    pygame.display.flip()

def game_loop():
    global player_x, lives, coin
    
    # Create initial obstacles
    create_obstacle()
    
    running = True
    while running:
        # Set FPS (frames per second)
        clock.tick(60)
        
        # Event handling
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
        
        # Move player based on user input (left and right)
        keys = pygame.key.get_pressed()
        if keys[pygame.K_LEFT] and player_x > 0:
            player_x -= player_speed
        if keys[pygame.K_RIGHT] and player_x < width - player_width:
            player_x += player_speed
        
        # Move obstacles and check for collisions
        move_obstacles()
        if check_collision():
            lives -= 1  # Decrease life on collision
            if lives <= 0:
                running = False  # End the game if no lives are left
            else:
                obstacles.clear()  # Clear obstacles after collision for a fresh start
        
        # Move the coin and check for collection
        coin = move_coin()
        check_coin_collection()
        
        # Periodically create new obstacles based on the increased difficulty
        if random.randint(1, 100) < obstacle_spawn_rate:
            create_obstacle()
        
        # Draw the game elements
        draw()
    
    pygame.quit()

# Run the game loop
game_loop()