package prueba1;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

public class VentanaSimple extends JFrame
{
    public VentanaSimple()
    {
        setBounds(50,50,500,500);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new FlowLayout());
        
        JLabel l = new JLabel("Escribe tu nombre");
        JLabel saludo = new JLabel();
        JTextField nombre = new JTextField("           ");
        JButton boton = new JButton("Saludo");

        boton.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent e) 
            {
                String name = nombre.getText();
                saludo.setText("Hola "+name);
                
            }
        });
        
        
        add(nombre);
        add(l);
        add(boton);
        add(saludo);
        
        setVisible(true);
    }
    
    public static void main(String[] args) 
    {   
        
        VentanaSimple v = new VentanaSimple();
    }
    
}
