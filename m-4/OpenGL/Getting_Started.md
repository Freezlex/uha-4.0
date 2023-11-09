# Initialiser un projet OpenGL

Ce document détaille la démarche à suivre pour l'initialisation d'un projet C++ utilisant OpenGL.

## Etape 1 : Initialiser le projet avec Visual Studio 22

Commencez par créer un projet vide en séléctionnant `Créer un projet`, puis séléctionnez `Projet Vide` pour language `C++` et enfin cliquez sur **Suivant**.
Initialisez le projet avec le nom de projet et l'emplacement désiré puis séléctionnez **Créer**.

## Etape 2 : Téléchargement et installation des dépendances GLFW

Une fois le projet initialisé, téléchargez les [binaries de **GLFW**](https://www.glfw.org/download.html) pour votre système d'exploitation ([Par défaut 64-bits Windows binaries](https://github.com/glfw/glfw/releases/download/3.3.8/glfw-3.3.8.bin.WIN64.zip)).

En allant dans le dossier contenant votre solutions, créez le dossier `Dependencies`. A l'interieur de ce dossier, ajoutez le dossier `GLFW`. Depuis l'archive `glfw-X.X.X.bin.XXX`, récupérez les dossiers `include` et `lib-vc2022` et copiez les dans le dossier `GLFW` créé précédement.

## Etape 3 : Configuration du projet avec GLFW

Une fois les dépendances ajoutées il faut s'assurer de certains paramétres pour que ces dernières soit prises en compte, pour ce faire séléctionnez le projet créé dans l'Explorateur de solutions puis avec le raccourcis clavier `Alt+Entrée` vous arriverez sur la **Page de propriétés** de votre projet.

Suivez dans l'ordre les trois étapes pour définir l'emplacement de notre biblotèque **GLFW** :
 * Dans la section `C/C++` -> `Général` insérez dans le champ **Autre répertoires Include** la valeur `$(SolutionDir)Dependencies\GLFW\include`
 * Dans la section `Editeur de liens` -> `Général` insérez dans le champ **Répertoires de bibliothèque supplémentaire** la valeur `$(SolutionDir)Dependencies\GLFW\lib-vc2022`
 * Dans la section `Editeur de liens` -> `Entrée` insérez dans le champ **Dépendances supplémentaires** la valeur `glfw3.lib;opengl32.lib;User32.lib;Gdi32.lib;Shell32.lib;`

## Etape 4 : Premiers pas

En copiant l'extrait de code ce-dessous, vérifiez que tout fonctionne comme souhaitez en essayant de lancer un build de l'application (Raccourci `Ctrl+B`).
```c++
#include <GLFW/glfw3.h>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "OpenGL - FR_MASTER", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
```

Si la compilation se déroule sans problèmes vous devriez voir le message suivant, dans le cas contraires vérifiez les différentes étapes effectuées :
```
L'opération de génération a démarré...
1>------ Début de la génération : Projet : OpenGLMaster, Configuration : Debug x64 ------
1>Application.cpp
1>OpenGLMaster.vcxproj -> C:\Users\Freezlex\Documents\Developpement\Work\OpenGLMaster\x64\Debug\OpenGLMaster.exe
========== Build : 1 réussite(s), 0 échec(s), 0 à jour, 0 ignorée(s) ==========
```
