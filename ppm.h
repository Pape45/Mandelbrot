#ifndef PPM_H
#define PPM_H

// Structure représentant un pixel dans une image PPM
struct ppm_pixel {
  unsigned char r;
  unsigned char g;
  unsigned char b;
};

// Fonction permettant de définir les valeurs RVB d'un pixel
static inline void ppm_setpixel(struct ppm_pixel *px, unsigned char r,
                                unsigned char g, unsigned char b) {
  px->r = r;
  px->g = g;
  px->b = b;
}

// Structure de représentation d'une image PPM
struct ppm_image {
  unsigned int width;
  unsigned int height;
  struct ppm_pixel *px;
};

// Fonction permettant d'initialiser une image PPM avec la largeur et la hauteur données et réservant la mémoire nécessaire
int ppm_image_init(struct ppm_image *im, int w, int h);

// Fonction permettant de libérer la mémoire allouée à une image PPM
int ppm_image_release(struct ppm_image *im);

// Fonction permettant de définir les valeurs RVB d'un pixel dans une image PPM
static inline void ppm_image_setpixel(struct ppm_image *im, int x, int y,
                                      unsigned char r, unsigned char g,
                                      unsigned char b) {
  struct ppm_pixel *px = im->px + im->width * y + x;
  ppm_setpixel(px, r, g, b);
}

// Fonction pour sauvegarder une image PPM dans un fichier
int ppm_image_dump(struct ppm_image *im, char *path);

#endif