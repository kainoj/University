package soundbank;

import java.awt.Container;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class UserInterface extends JComponent {
    
    JFrame frame;
    Song song;
    SoundPlayer player;
    
    UserInterface(  Setlist setlist, int songNumber  ) {
        frame = new JFrame(Consts.WIN_TITLE);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      
        Container kontener = frame.getContentPane();
        GridLayout layout = new GridLayout(15,1);
        layout.setVgap(7);
        layout.setHgap(7);
        kontener.setLayout(layout);
        
        player = new SoundPlayer();
        //
        song = setlist.getNthSong(songNumber);
        int setlen = setlist.size();
        //
        
        JButton button_prevSong = new JButton("<");
        JButton button_nextSong = new JButton(">");
        
        button_nextSong.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                
                switchSong(setlist, setlist.getNextSongIndex(songNumber));       
            }
        });
        button_prevSong.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
              
                UserInterface u = switchSong(setlist, setlist.getPrevSongIndex(songNumber));
            }
        });
        
        JPanel topPane = new JPanel(new GridLayout(1,3));
        topPane.add(button_prevSong);
        topPane.add(new JLabel( song.getTitle() ));
        topPane.add(button_nextSong);
        
        kontener.add(topPane);

        JButton[] button_song = new JButton[ song.size() ];
        
        
        // Song list
        for(int i=0; i< song.size() ; i++) {
            if(!Consts.MSG_PATH.equals(song.getSong().get(i).getPath())) {
                JButton button_playable =  new JButton(song.getSong().get(i).getTitle() );
                button_playable.setPreferredSize(new Dimension(100, 100)); 
                
                
                String currenttitle = song.getNthSound(i).getPath();
                button_playable.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        
                        System.out.println("odtwarzam " + currenttitle);
                        
                            player.play(currenttitle);
                       
                        System.out.println("asddsddd ");
           
                    }
                });
                
                button_song[i]  = button_playable;       
                kontener.add(button_song[i]);
            }
            else {
                System.out.println("Pominalem utwor bez sciezki");
            }
        }
        

        JButton button_editSongs = new JButton(Consts.BUTTON_MSG_EDIT);
        button_editSongs.addActionListener( new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                frame.dispose();
                SongEditor editor = new SongEditor(setlist, songNumber);
            }
        });
        
        
        kontener.add(button_editSongs);
               
        //frame.pack();
        frame.setSize(450, 700);
        frame.setVisible(true);
        
        
    }

    public UserInterface(Setlist setlist) {
        this(setlist, 0);
    }
    
    public UserInterface() {
        // tu zaladuj z pliku
        
        this(new Setlist(), 0);
    }
    
    
    private UserInterface switchSong(Setlist setlist, int  number) {
        frame.dispose();
        return new UserInterface(setlist, number);
        
    }
    
}
