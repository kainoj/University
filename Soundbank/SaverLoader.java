package soundbank;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class SaverLoader { //pobaw sie w generyczna
    Setlist setlist;
    static Setlist set;
    
    public SaverLoader(Setlist s1) {
        setlist = s1;
    } 
    
    public SaverLoader() {
        setlist = new Setlist(new Song(new Sound(1, Consts.MSG_TITLE, Consts.MSG_PATH)));
    }
    
    public void save() {
        //zaladuj do pliku
        FileOutputStream fos = null;
        ObjectOutputStream oos = null;
        try {
            fos= new FileOutputStream(Consts.FILE_PATH); 
            oos = new ObjectOutputStream(fos); 
            oos.writeObject(setlist);
            oos.close();
            fos.close();
        } 
        catch (FileNotFoundException e) {
            System.out.println(e);
        } 
        catch (IOException e) {
            System.out.println(e);
        }
    }
        
    public static Setlist load() {
        FileInputStream fis = null;
        ObjectInputStream ois = null;
        
        try  {
            fis= new FileInputStream(Consts.FILE_PATH);
            ois = new ObjectInputStream(fis);
            set = (Setlist) ois.readObject();
            ois.close();
            fis.close();
        }
        catch(FileNotFoundException e) {
            //System.out.println(e);
            return new Setlist(new Song(  new Sound(1, Consts.MSG_TITLE, Consts.MSG_PATH)));
        }
        catch(IOException i) {
            System.out.print(i);
        }
        catch(ClassNotFoundException c)
        {
            System.out.println("Nie ma takiej klasy...");
        }
        
        return set;
    }
}
