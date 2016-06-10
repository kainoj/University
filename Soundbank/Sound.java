package soundbank;

import java.io.Serializable;

public class Sound implements Serializable{
    
    private int songid;
    private String title;
    private String path;
    
    public Sound(int s_id, String s_title, String s_path) {
        songid = s_id;
        title = s_title;
        path = s_path;
    }
    
    public Sound() {
        this(42, Consts.MSG_TITLE, Consts.MSG_PATH);
    }
    
    public int getId() {
        return songid;
    }
    
    public String getTitle() {
        return title;
    }
    
    public String getPath() {
        return path;
    }
    
    public void setTitle(String new_title) {
        title = new_title;
    }
    
    public void setPath(String new_path) {
        path = new_path;        
    }
    
}
