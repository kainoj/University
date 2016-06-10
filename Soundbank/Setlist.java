package soundbank;

import java.io.Serializable;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class Setlist implements Serializable{
    
    private List<Song> setlist;
    
    public Setlist(List<Song> songs) {
        setlist = new LinkedList(songs);
    }
    
    public Setlist(Song song){
        setlist = new LinkedList();
        setlist.add(song);
    }

    Setlist() {
        setlist = Collections.emptyList();
    }
    
    public Song getNthSong(int nth) {
        return setlist.get(nth);       
    }
    
    public List<Song> getSetlist() {
        return setlist;
    }
    
    public int size() {
        return setlist.size();
    }
    
    public void updateNthSong(Song udpatedSong, int nth) {
        setlist.set(nth, udpatedSong);
    } 
    
    public void addNewSong(Song s) {
        setlist.add(s);
    }
    
    public int getNextSongIndex(int currSongNumber) {   // jezeli jestesmy w ostatniej piosence setlisty, to do konca setlisty dolaczamy nowa, pusta piosenke
        if(currSongNumber +1 >= setlist.size() ) {
                this.addNewSong( new Song() );     
        }
        return currSongNumber+1;        
    }
    
    public int getPrevSongIndex(int currSongNumber) { //set jest cykliczny
        if( currSongNumber == 0 )
            return this.size()-1;
        //System.out.println("nowe poprzednie: "+ Integer.toString(currSongNumber));
        return currSongNumber-1;
        
    }
    
}