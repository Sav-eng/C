
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author apirakhoonlor
 */
public class Ones {
    
	public static void main(String[] args) throws IOException {
		
		 BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in)); 
		 String line = stdin.readLine(); 
		 int numTestCase = Integer.parseInt(line.trim());		 
		 for(int i=0 ; i < numTestCase ; i++){
			 line = stdin.readLine();
                         System.out.println(countZeros(line.trim()));
		 }
	}
        
        public static int countZeros(String input){
            int ilength = input.length();
            if(ilength > 250){
                System.out.println("ERROR");
            }
            int i;
            int count = 0;           
            for(i = 1; i < ilength; i++){
                count = count + getCount(input.charAt(i-1),input.charAt(i));
            }
            if(input.charAt(ilength - 1) == '0'){
                count++;
            }
            return count;
        }
        
        public static int getCount(char prev, char curr){
                switch(curr){
                    case '1':
                        if(prev == '0' || prev == '2' || prev == '4' || prev == '6' || prev == '8')
                            return 1;
                    case '2':
                        if(prev == '0' || prev == '4' || prev == '8')
                            return 1;                                                
                    case '3':
                        if(prev == '0' || prev == '4' || prev == '8')
                            return 1;                    
                    case '4':
                        if(prev == '0' || prev == '8'){
                            return 1;                        
                        }
                    case '5':
                        if(prev == '0' || prev == '8'){
                            return 1;                        
                        }
                    case '6':
                        if(prev == '0' || prev == '8'){
                            return 1;                        
                        }
                    case '7':
                        if(prev == '0' || prev == '8'){
                            return 1;                        
                        }
                    case '8':
                        if(prev == '0'){
                            return 1;                        
                        }
                    case '9':
                        if(prev == '0'){
                            return 1;                        
                        }
                }
                return 0;
        }
}
