package soundbank;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javazoom.jl.decoder.JavaLayerException;
import javazoom.jl.player.advanced.AdvancedPlayer;
import javazoom.jl.player.advanced.PlaybackEvent;
import javazoom.jl.player.advanced.PlaybackListener;

public class SoundPlayer  {
    
    Thread sound;
    AdvancedPlayer player;
    Boolean isPlayed;
    String path;
    int pausedOnFrame = 0;
    Runnable r;
    
    public SoundPlayer() {
        isPlayed = false;
        player   = null;
        
        
        r = new Runnable() {
            @Override
            public void run() {
                createPlayer(); 
            }}   ;   
    }
    
    public void play(String newpath)  {
        path     = newpath;
        isPlayed = true;
        Thread s = new Thread(r);
        s.start();
        System.out.println("started: " + newpath);
    }
    
    public void stop() {
        System.out.println("stop!");
        isPlayed = false;
        // stop all sounds+++  
    }
  
    
    /*
    w wersji, w ktorej moge odtwarzac wiele dziwekow jednoczesnie nie potrzebuje funkcji pasue oraz resume
    public void pause() {
         System.out.println("pauza");
    }
  
    public void resume() {
        System.out.println("kontynuuje");
        // play the sound
    }
    
    */
    
    
    private void createPlayer() {
        
        if(isPlayed == true) {
            try {
                // tworzenie odtwrzaca
                player = new AdvancedPlayer(new FileInputStream(path.replace('\\', '/')));
            } catch (JavaLayerException | FileNotFoundException ex) {
                Logger.getLogger(SoundPlayer.class.getName()).log(Level.SEVERE, null, ex);
            }

            player.setPlayBackListener(new PlaybackListener() {
            @Override
            public void playbackFinished(PlaybackEvent event) {
                pausedOnFrame = event.getFrame();
            }});    
             try {
                player.play();
            } catch (JavaLayerException ex) {
                Logger.getLogger(SoundPlayer.class.getName()).log(Level.SEVERE, null, ex);
            }
        }  
    }
}
