
import sys
import cfg
import pygame
from modules import *


def GamingInterface(num_player, screen):

    pygame.mixer.music.load(cfg.SOUNDPATHS['Cool Space Music'])
    pygame.mixer.music.set_volume(0.4)
    pygame.mixer.music.play(-1)
    explosion_sound = pygame.mixer.Sound(cfg.SOUNDPATHS['boom'])
    fire_sound = pygame.mixer.Sound(cfg.SOUNDPATHS['shot'])
    font = pygame.font.Font(cfg.FONTPATH, 20)

    bg_imgs = [cfg.IMAGEPATHS['bg_big'],
               cfg.IMAGEPATHS['seamless_space'], cfg.IMAGEPATHS['space3']]
    bg_move_dis = 0
    bg_1 = pygame.image.load(bg_imgs[0]).convert()
    bg_2 = pygame.image.load(bg_imgs[1]).convert()
    bg_3 = pygame.image.load(bg_imgs[2]).convert()

    player_group = pygame.sprite.Group()
    bullet_group = pygame.sprite.Group()
    asteroid_group = pygame.sprite.Group()

    asteroid_ticks = 90

    for i in range(num_player):
        player_group.add(Ship(i+1, cfg))
    clock = pygame.time.Clock()

    score_1, score_2 = 0, 0

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

        pressed_keys = pygame.key.get_pressed()
        for idx, player in enumerate(player_group):
            direction = None
            if idx == 0:
                if pressed_keys[pygame.K_UP]:
                    direction = 'up'
                elif pressed_keys[pygame.K_DOWN]:
                    direction = 'down'
                elif pressed_keys[pygame.K_LEFT]:
                    direction = 'left'
                elif pressed_keys[pygame.K_RIGHT]:
                    direction = 'right'
                if direction:
                    player.move(direction)
                if pressed_keys[pygame.K_j]:
                    if player.cooling_time == 0:
                        fire_sound.play()
                        bullet_group.add(player.shot())
                        player.cooling_time = 20

            elif idx == 1:
                if pressed_keys[pygame.K_w]:
                    direction = 'up'
                elif pressed_keys[pygame.K_s]:
                    direction = 'down'
                elif pressed_keys[pygame.K_a]:
                    direction = 'left'
                elif pressed_keys[pygame.K_d]:
                    direction = 'right'
                if direction:
                    player.move(direction)
                if pressed_keys[pygame.K_SPACE]:
                    if player.cooling_time == 0:
                        fire_sound.play()
                        bullet_group.add(player.shot())
                        player.cooling_time = 20

            if player.cooling_time > 0:
                player.cooling_time -= 1

        if (score_1 + score_2) < 500:
            background = bg_1
        elif (score_1 + score_2) < 1500:
            background = bg_2
        else:
            background = bg_3

        screen.blit(
            background, (0, -background.get_rect().height + bg_move_dis))
        screen.blit(background, (0, bg_move_dis))
        bg_move_dis = (bg_move_dis + 2) % background.get_rect().height

        if asteroid_ticks == 0:
            asteroid_ticks = 90
            asteroid_group.add(Asteroid(cfg))
        else:
            asteroid_ticks -= 1

        for player in player_group:
            if pygame.sprite.spritecollide(player, asteroid_group, True, None):
                player.explode_stop = 1
                explosion_sound.play()
            elif player.explode_stop > 0:
                if player.explode_stop > 3:
                    player_group.remove(player)
                    if len(player_group) == 0:
                        return
                else:
                    player.explode(screen)

            else:
                player.draw(screen)

        for bullet in bullet_group:
            bullet.move()
            if pygame.sprite.spritecollide(bullet, asteroid_group, True, None):
                bullet_group.remove(bullet)
                if bullet.player_idx == 1:
                    score_1 += 1
                else:
                    score_2 += 1
            else:
                bullet.draw(screen)

        for asteroid in asteroid_group:
            asteroid.move()
            asteroid.rotate()
            asteroid.draw(screen)

        score_1_text = 'Player1 Score: %s' % score_1
        score_2_text = 'Player2 Score: %s' % score_2
        text_1 = font.render(score_1_text, True, (0, 0, 255))
        text_2 = font.render(score_2_text, True, (255, 0, 0))
        screen.blit(text_1, (2, 5))
        screen.blit(text_2, (2, 35))

        pygame.display.update()
        clock.tick(60)


def main():
    pygame.init()
    pygame.font.init()
    pygame.mixer.init()
    screen = pygame.display.set_mode(cfg.SCREENSIZE)
    pygame.display.set_caption('Meteor Game')
    num_player = StartInterface(screen, cfg)
    if num_player == 1:
        while True:
            GamingInterface(num_player=1, screen=screen)
            EndInterface(screen, cfg)
    else:
        while True:
            GamingInterface(num_player=2, screen=screen)
            EndInterface(screen, cfg)


if __name__ == '__main__':
    main()
