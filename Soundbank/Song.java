package soundbank;

import java.io.Serializable;
import java.util.LinkedList;
import java.util.List;

public class Song implements Serializable{
    
    List<Sound> song;
    String title;
    int id; // id jest indeksem w setliscie
    
    public Song(List<Sound> sounds) {
         song = new LinkedList(sounds);
    }
    public Song(List<Sound> sounds, String stitle) {
         song = new LinkedList(sounds);
         title = stitle;
    }
    
    public Song(Sound s) {
        song = new LinkedList();
        song.add(s);
    }
    
     public Song() {
        this(new Sound());
    }
    
    
    public List<Sound> getSong() {
        return song;        
    }
    
   
    public void updateSong( List<Sound> updatedsong, String newTitle ){
        title = newTitle;
        song.clear();
        for(Sound s: updatedsong)
            song.add(s);
    }
    
    public void updateSong( List<Sound> updatedsong) {
        updateSong(updatedsong, this.title);
    }
    
    public String getTitle() {
        return title;
    }
    
    public Sound getNthSound(int nth) {
        return song.get(nth);
    }
    
    public int size() {
        return song.size();
    }
    
    public int getId() {
        return id;
    }
   
}
