
import pygame
import random


class Bullet(pygame.sprite.Sprite):
    def __init__(self, idx, position, cfg):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.image.load(
            cfg.IMAGEPATHS['bullet']).convert_alpha()
        self.image = pygame.transform.scale(self.image, (10, 10))

        self.rect = self.image.get_rect()
        self.rect.left, self.rect.top = position
        self.position = position

        self.speed = 8

        self.player_idx = idx

    def move(self):
        self.position = self.position[0], self.position[1] - self.speed
        self.rect.left, self.rect.top = self.position

    def draw(self, screen):
        screen.blit(self.image, self.rect)


class Asteroid(pygame.sprite.Sprite):
    def __init__(self, cfg):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.image.load(
            cfg.IMAGEPATHS['asteroid']).convert_alpha()

        self.rect = self.image.get_rect()
        self.position = (random.randrange(20, cfg.SCREENSIZE[0] - 20), -64)
        self.rect.left, self.rect.top = self.position

        self.speed = random.randrange(3, 9)
        self.angle = 0
        self.angular_velocity = random.randrange(1, 5)
        self.rotate_ticks = 3

    def move(self):
        self.position = self.position[0], self.position[1] + self.speed
        self.rect.left, self.rect.top = self.position

    def rotate(self):
        self.rotate_ticks -= 1
        if self.rotate_ticks == 0:
            self.angle = (self.angle + self.angular_velocity) % 360
            orig_rect = self.image.get_rect()
            rot_image = pygame.transform.rotate(self.image, self.angle)
            rot_rect = orig_rect.copy()
            rot_rect.center = rot_image.get_rect().center
            rot_image = rot_image.subsurface(rot_rect).copy()
            self.image = rot_image
            self.rotate_ticks = 3

    def draw(self, screen):
        screen.blit(self.image, self.rect)


class Ship(pygame.sprite.Sprite):
    def __init__(self, idx, cfg):
        pygame.sprite.Sprite.__init__(self)
        self.cfg = cfg
        self.image = pygame.image.load(cfg.IMAGEPATHS['ship']).convert_alpha()
        self.explode_image = pygame.image.load(
            cfg.IMAGEPATHS['ship_exploded']).convert_alpha()

        self.position = {
            'x': random.randrange(-10, 918), 'y': random.randrange(-10, 520)}
        self.rect = self.image.get_rect()
        self.rect.left, self.rect.top = self.position['x'], self.position['y']

        self.speed = {'x': 10, 'y': 5}

        self.player_idx = idx

        self.cooling_time = 0
        self.explode_stop = 0

    def explode(self, screen):
        img = self.explode_image.subsurface(
            (48 * (self.explode_stop - 1), 0), (48, 48))
        screen.blit(img, (self.position['x'], self.position['y']))
        self.explode_stop += 1

    def move(self, direction):
        if direction == 'left':
            self.position['x'] = max(-self.speed['x'] +
                                     self.position['x'], -10)
        elif direction == 'right':
            self.position['x'] = min(self.speed['x'] + self.position['x'], 918)
        elif direction == 'up':
            self.position['y'] = max(-self.speed['y'] +
                                     self.position['y'], -10)
        elif direction == 'down':
            self.position['y'] = min(self.speed['y'] + self.position['y'], 520)
        self.rect.left, self.rect.top = self.position['x'], self.position['y']

    def draw(self, screen):
        screen.blit(self.image, self.rect)

    def shot(self):
        return Bullet(self.player_idx, (self.rect.center[0] - 5, self.position['y'] - 5), self.cfg)
