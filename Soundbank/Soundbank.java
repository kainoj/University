package soundbank;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;



public class Soundbank {

    public static void main(String[] args) {
        
        // ustawienie systemowego wyglądu okienek
        try {
            UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
        } catch (ClassNotFoundException | InstantiationException | IllegalAccessException | UnsupportedLookAndFeelException ex) {
            Logger.getLogger(Soundbank.class.getName()).log(Level.SEVERE, null, ex);
        } 
     //   Setlist testSet = new Setlist(new Song(new Sound(1, Consts.MSG_TITLE, Consts.MSG_PATH)));
        UserInterface ui = new UserInterface(SaverLoader.load());
     
    }    
}
