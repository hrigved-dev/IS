package test;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.Cipher;

public class main {
    public static void main(String[] args) {
        try {
            KeyGenerator kg = KeyGenerator.getInstance("DES");
            SecretKey myDESKey = kg.generateKey();
            Cipher cipher = Cipher.getInstance("DES/ECB/PKCS5Padding");

            cipher.init(Cipher.ENCRYPT_MODE, myDESKey);

            byte[] text = "Plaintext".getBytes();
            System.out.println("Text in bytes: " + text);
            System.out.println("Text: " + new String(text));

            byte[] textEnc = cipher.doFinal(text);
            System.out.println("Text Encrypted: " + new String(textEnc));

            cipher.init(Cipher.DECRYPT_MODE, myDESKey);
            byte[] textDec = cipher.doFinal(textEnc);
            System.out.println("Text Decrypted: " + new String(textDec));


        } catch (Exception e) {
            
        }
    }
}