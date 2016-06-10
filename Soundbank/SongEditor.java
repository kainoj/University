package soundbank;

import java.awt.Component;
import java.awt.Container;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.util.LinkedList;
import java.util.List;
import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.filechooser.FileNameExtensionFilter;

public class SongEditor extends JComponent {
    
    JFrame frame;
    Container kontener;
    GridLayout layout;
    
    JPanel topPane;          // gorny panel z menu
    List<JPanel> panel_song; // lista panelow, kazdy z nich zawiera 'modul' do edycji poszczegolnego dwieku
    Song song;
    Setlist setlist;
    int songnumber;
    
    SongEditor(Setlist set, int snmbr)  {
        setlist = set;
        songnumber = snmbr;
        
        frame = new JFrame(Consts.WIN_TITLE+": "+Consts.WIN_TITLE_EDIT);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        layout = new GridLayout(15,1);
        layout.setVgap(7);
        layout.setHgap(17);
        
        kontener = frame.getContentPane();
        kontener.setLayout(layout);
        
        panel_song = new LinkedList();
        song = setlist.getNthSong(songnumber);
        int numberOfSamples = song.size();
       
        ////////////////////////////////////////
        /////////////  Przyciski  //////////////
        ////////////////////////////////////////
        
        JTextField field_currSong  = new JTextField(song.getTitle(), 30);
        JButton button_saveSong    = new JButton(Consts.BUTTON_MSG_SAVE);
        JButton button_dismissSong = new JButton(Consts.BUTTON_MSG_DISMISS);
        
        button_dismissSong.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
               returnToUI();  
            }
        });
       
        button_saveSong.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                List<Sound> s = new LinkedList();
                
                System.out.println("Zapisuje: ");
                for(int i=0; i<panel_song.size(); i++) {            ////////////////////////////////////////  3 -> dowolna li   iczba
                    Component[] comp = panel_song.get(i).getComponents();
                    
                    System.out.print( ((JTextField)comp[0]).getText()+"\t");
                    System.out.print( ((JTextField)comp[1]).getText()+"\n");
                    //System.out.print( ((JTextField)comp[2]).getText()+"\n");
                    
                    s.add(new Sound(
                            //Integer.parseInt(((JTextField)comp[0]).getText()),  // id
                            42,
                            ((JTextField)comp[0]).getText(),                    // nazwa
                            ((JTextField)comp[1]).getText()                     // path
                           )                           
                    );                            
                }
                frame.dispose();
                setlist.updateNthSong(new Song(s, field_currSong.getText()), songnumber);
                SaverLoader saver = new SaverLoader( setlist );
                saver.save();

                frame.dispose();
                returnToUI();                
            }
        });
        
 
        topPane = new JPanel(new GridLayout(1,3));
        topPane.add(field_currSong);
        topPane.add(button_saveSong);
        topPane.add(button_dismissSong);
       
        
        JButton button_newSample = new JButton(Consts.BUTTON_MSG_ADD);
        kontener.add(topPane);
        kontener.add(button_newSample);
        
        button_newSample.addActionListener(  new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JPanel panel_newSong = newSongPanel();
                panel_song.add(panel_newSong);
                kontener.add(panel_newSong);
                frame.validate(); // aktualizacja okna
                frame.repaint(); 
            }
        } );
        
        for(int i=0; i<numberOfSamples; i++) {
            if(!song.getNthSound(i).getTitle().equals(Consts.MSG_PATH)) {
            JPanel panel_newSong = newSongPanel(song.getNthSound(i).getId(), 
                                                song.getNthSound(i).getTitle(),
                                                song.getNthSound(i).getPath()
                                                );
            panel_song.add(panel_newSong);
            kontener.add(panel_newSong);
            }
        }
        
        //frame.pack();
        frame.setSize(450, 700);
        frame.setVisible(true);
    }
    
    
   
    
    private JPanel newSongPanel(int nmbr, String stitle, String spath) {
        JTextField nth  = new JTextField(Integer.toString(nmbr), 1);
        JTextField titl = new JTextField(stitle, 40);
        JTextField path = new JTextField(spath, 120);
        JButton chos    = new JButton( Consts.BUTTON_MSG_FILE );
        JButton rm      = new JButton("x");

        chos.addActionListener( new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                final JFileChooser fc = new JFileChooser();
                fc.setFileFilter(new FileNameExtensionFilter(Consts.MSG_FILES, "mp3", "wav"));
                int returnVal = fc.showOpenDialog(SongEditor.this);
                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    File file = fc.getSelectedFile();
                    path.setText(file.getAbsolutePath());
                    System.out.println("Opening: " + file.getAbsolutePath() + ".");
                } else {
                    System.out.println("Open command cancelled by user." );
                }
            }
        });
        
        JPanel panel_songNew = new JPanel( new GridLayout(1,5));
        
        rm.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                panel_song.remove(panel_songNew);
                frame.getContentPane().remove(panel_songNew);
                frame.validate(); // aktualizacja okna
                frame.repaint(); 
                System.out.println("Usiuwam");
            }
        });
        
      
//        panel_songNew.add(nth);
        panel_songNew.add(titl);
        panel_songNew.add(path);
        panel_songNew.add(chos);
        panel_songNew.add(rm);
        return panel_songNew;
    }
    
    private JPanel newSongPanel() {
        return newSongPanel(42, Consts.MSG_TITLE, Consts.MSG_PATH );
    }
    
    private UserInterface returnToUI() {
        frame.dispose();
        return new UserInterface(setlist, songnumber);
    }

}
