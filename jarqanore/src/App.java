import be.labruyere.arqanore.*;
import be.labruyere.arqanore.enums.Keys;
import be.labruyere.arqanore.exceptions.ArqanoreException;

import java.util.Arrays;

public class App {
    private static Window window;

    private static void onOpen() {
        
    }

    private static void onClose() {
        
    }

    private static void onUpdate(double at) {
        try {
            if (Keyboard.keyPressed(Keys.ESCAPE)) {
                window.close();
            }
        } catch (ArqanoreException ex) {
            ex.printStackTrace();
            window.close();
        }
    }

    private static void onRender3D() {
        
    }

    private static void onOpenGL(String type, String severity, String message) {
        System.out.println("[" + type + "][" + severity + "] " + message);
    }

    public static void main(String[] args) {
        var fqn = "App";

        try {
            window = new Window(1440, 786, "App");
            window.onOpen(fqn, "onOpen");
            window.onClose(fqn, "onClose");
            window.onUpdate(fqn, "onUpdate");
            window.onRender3D(fqn, "onRender3D");
            window.onOpenGL(fqn, "onOpenGL");
            window.open(false, true);
        } catch (ArqanoreException e) {
            e.printStackTrace();
        } finally {
            window.delete();
        }
    }
}
