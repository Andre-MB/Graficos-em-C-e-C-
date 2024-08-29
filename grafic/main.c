#include <stdio.h>
#include <stdlib.h>

#include <GL/glx.h>
#include <GL/gl.h>
#include <GL/glut.h>

#include <string.h>

// Função para desenhar uma coluna
void drawColumn(float x, float height, float width, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
        glVertex2f(x, 100.0f);
        glVertex2f(x + width, 100.0f);
        glVertex2f(x + width, height + 100.0f);
        glVertex2f(x, height + 100.0f);
    glEnd();
}

// Função para desenhar uma barra horizontal
void drawBar(float y, float width, float height, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
        glVertex2f(0.0f, y);
        glVertex2f(width, y);
        glVertex2f(width, y + height);
        glVertex2f(0.0f, y + height);
    glEnd();
}

// Função para desenhar uma linha
void drawLine(float x1, float y1, float x2, float y2, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    glEnd();
}

// Função para desenhar texto na tela
void drawText(float x, float y, const char* text) {
    glColor3f(0.0f, 0.0f, 0.0f); // Cor do texto (preto)
    glRasterPos2f(x, y);
    const char *c;
    for (c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

}

int main(int argc, char **argv) {
    glutInit(&argc, argv); // Chamando glutInit


    Display *dpy = XOpenDisplay(NULL); // Conecta ao servidor de exibição

    if(dpy == NULL) {
        printf("Não foi possível abrir a exibição\n");
        exit(1);
    }

    int screen = DefaultScreen(dpy);
    Window root = RootWindow(dpy, screen);

    GLint att[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
    XVisualInfo *vi = glXChooseVisual(dpy, 0, att);
    if(vi == NULL) {
        printf("Nenhum visual apropriado encontrado\n");
        exit(1);
    }

    Colormap cmap = XCreateColormap(dpy, root, vi->visual, AllocNone);
    XSetWindowAttributes swa;
    swa.colormap = cmap;
    swa.event_mask = ExposureMask | KeyPressMask;

    Window win = XCreateWindow(dpy, root, 0, 0, 1200, 700, 0, vi->depth, InputOutput, vi->visual,
                               CWColormap | CWEventMask, &swa);
    XMapWindow(dpy, win);
    XStoreName(dpy, win, "Gráfico de Colunas");

    GLXContext glc = glXCreateContext(dpy, vi, NULL, GL_TRUE);
    glXMakeCurrent(dpy, win, glc);

    glClearColor(1.0, 1.0, 1.0, 1.0); // Fundo branco
    glOrtho(0, 1200, 0, 700, -1, 1);   // Define projeção ortográfica

    while(1) {
        XEvent xev;
        XNextEvent(dpy, &xev);

        if(xev.type == Expose) {
            glClear(GL_COLOR_BUFFER_BIT);

            // Desenhar linhas horizontais
            int px = 0;

            while(px <= 400){
                px += 100;
                drawLine(150.0f, px, 1050.0f, px, 0.0f, 0.0f, 0.0f);
            }

            // Desenhar primeiro grupo de colunas
            drawColumn(250.0f, 100.0f, 50.0f, 1.0f, 0.0f, 0.5f); // Coluna vermelha
            drawColumn(300.0f, 300.0f, 50.0f, 0.0f, 0.8f, 0.6f); // Coluna verde
            drawColumn(350.0f, 400.0f, 50.0f, 0.0f, 0.0f, 0.8f); // Coluna azul

            drawColumn(500.0f, 250.0f, 50.0f, 1.0f, 0.0f, 0.5f); // Coluna vermelha
            drawColumn(550.0f, 350.0f, 50.0f, 0.0f, 0.8f, 0.6f); // Coluna verde
            drawColumn(600.0f, 230.0f, 50.0f, 0.0f, 0.0f, 0.8f); // Coluna azul

            drawColumn(800.0f, 150.0f, 50.0f, 1.0f, 0.0f, 0.5f); // Coluna vermelha
            drawColumn(850.0f, 310.0f, 50.0f, 0.0f, 0.8f, 0.6f); // Coluna verde
            drawColumn(900.0f, 170.0f, 50.0f, 0.0f, 0.0f, 0.8f); // Coluna azul



            // Desenhar linhas verticais
            drawLine(150.0f, 100.0f, 150.0f, 600.0f, 0.0f, 0.0f, 0.0f);



            drawText(115.0f, 195.0f, "50");
            drawText(110.0f, 295.0f, "100");
            drawText(110.0f, 395.0f, "150");
            drawText(110.0f, 495.0f, "200");

            drawText(280.0f, 80.0f, "Janeiro");
            drawText(540.0f, 80.0f, "Fevereiro");
            drawText(850.0f, 80.0f, "Marco");


            glXSwapBuffers(dpy, win);
        }

        if(xev.type == KeyPress) {
            KeySym key = XLookupKeysym(&xev.xkey, 0);
            if(key == XK_Escape) {
                break;
            }
        }
    }

    glXMakeCurrent(dpy, None, NULL);
    glXDestroyContext(dpy, glc);
    XDestroyWindow(dpy, win);
    XCloseDisplay(dpy);

    return 0;
}
