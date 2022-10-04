import pygame, sys
import time
import random

pygame.init()

window_ht = 600
window_wt = 1000

black = (0, 0 , 0)
white = (255, 255, 255)
red = (255, 0, 0)
blue = (0, 255, 0)
green = (0, 0 ,255)

window = pygame.display.set_mode([window_wt,window_ht])
pygame.display.set_caption('Pong')

screen = pygame.display.get_surface()

#initial coordinates of the paddle
rect_x = 500
rect_y = 580

#initial speed of the paddle
rect_x_change = 0
rect_y_change = 0

#initial position of the ball
ball_x = 50
ball_y = 50

ball_x_change = 5
ball_y_change = 5

score = 0

def drawrect(screen,x,y):
    if x <= 0:
        x = 0
    if x >= 899:
        x = 899
    pygame.draw.rect(screen,red,[x,y,100,20])

# game's main loop
done = False
clock = pygame.time.Clock()
FPS = 60

while not done:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = True
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                rect_x_change = -6
            elif event.key == pygame.K_RIGHT:
                rect_x_change = 6
        elif event.type == pygame.KEYUP:
            if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                rect_x_change = 0
            elif event.key == pygame.K_UP or event.key == pygame.K_DOWN:
                rect_y_change = 0

    screen.fill(black)
    
    rect_x += rect_x_change
    rect_y += rect_y_change
    
    ball_x += ball_x_change
    ball_y += ball_y_change


    if ball_x < 0:
        ball_x = 0
        ball_x_change = ball_x_change * -1
    elif ball_x > 985:
        ball_x = 985
        ball_x_change = ball_x_change * -1
    
    if ball_y < 0:
        ball_y = 0
        ball_y_change = ball_y_change * -1
    elif ball_x > rect_x and ball_x < rect_x +100 and ball_y == 565:
        ball_y_change = ball_y_change * -1
        score += 1
        FPS += 1
    elif ball_y > 600:
        ball_y_change = ball_y_change * -1
        score = 0
        FPS = 60
    pygame.draw.rect(screen,white,[ball_x,ball_y,15,15])

    drawrect(screen, rect_x, rect_y)

    #score board
    font = pygame.font.SysFont('Calibri',15,False,False)
    text = font.render("Score = " + str(score), True, white)
    screen.blit(text,[800,100])

    pygame.display.flip()
    clock.tick(FPS)

pygame.quit()


