/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author hiddendimension
 */
public class unix_dir {
    
    public String MainEx(char[] a){
        
        
        String s="";
        
        
        char c=a[0];
        
        for(int i=0;i<a.length;i++){
            
            
            if(a[i]>=c){
                c=a[i];
                
                s= Character.toString(a[i])+s;
                
            }
            else
                s= s+ Character.toString(a[i]);
            
            
            
        }
        
        
        return s;
    }
    
    
    
}
