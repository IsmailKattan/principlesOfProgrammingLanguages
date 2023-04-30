package javaFileReader;
import java.io.*;
/**anahtar kelimeler :
 * PDP
 * Gaziantep
 * Halep
 * AI/MachineLearning
 * */ 

// bu sınıf dosya okuma ,dosyadaki yorum sayma ve sınıflandırma amacıyla yapılmıştır
public class JavaFileProcess {

	private String fileName;      // dosya adı tutar ve kuruyucu vasıtasıyla değer alır
	
	public JavaFileProcess(String fileName)
	{
		this.fileName = fileName;
	}
	
	// bütün işlemler bu fonksiyonda gerçekleşmektedir
	public void getAllFile() throws IOException      
	{
		FileWriter singleLine = new FileWriter("teksatir.txt",false);
		FileWriter multiLine = new FileWriter("coksatir.txt",false);
		FileWriter javaDoc = new FileWriter("javadoc.txt",false);
		File file = new File(fileName);
		FileReader reader = new FileReader(file);
		Stack brackets = new Stack();
		CommentProcesser comment = new CommentProcesser();
		int commentLineCounter = 0;
		int multilineCommentCounter = 0;
		int javaDocCommentCounter = 0;
		try (BufferedReader br = new BufferedReader(reader)) {
			String line;
			while ((line = br.readLine()) != null) {
				
			    for(int i = 0;i<line.length();i++)
			    {
			    	if(line.charAt(i) == '{' || line.charAt(i) == '(')   // char yıgına veri ekleme 
			    	{
			    		brackets.push(line.charAt(i));
			    	}
			    	if(line.charAt(i) == '}' || line.charAt(i) == ')')  // fonksiyon kapatıldığı halde yorumlardan bilgi veririr ve char yıgından veri çıkatma
			    	{
			    		if(line.charAt(i)=='}' && brackets.getcount()>1)
			    		{
			    			printTab(brackets.getcount()+1);
					    	System.out.println("numberof single line comment: " + commentLineCounter);
					    	singleLine.write("numberof single line comment: " + commentLineCounter + "\n----------------------------------------------------\n");
					    	printTab(brackets.getcount()+1);
					    	System.out.println("number of multiline  comment: " + multilineCommentCounter);
					    	multiLine.write("number of multiline  comment: " + multilineCommentCounter + "\n----------------------------------------------------\n");
					    	printTab(brackets.getcount()+1);
					    	System.out.println("number  of  javadoc  comment: " + javaDocCommentCounter);
					    	printTab(brackets.getcount());
					    	System.out.println("----------------------------------------------------");
					    	javaDoc.write("number  of  javadoc  comment: " + javaDocCommentCounter + "\n----------------------------------------------------\n");
					    	commentLineCounter = 0;
					    	multilineCommentCounter = 0;
					    	javaDocCommentCounter = 0; 
			    		}
			    		brackets.pull();
			    	}
			    }
			    if(StringProcesser.isThereClass(line)) // satırda sınıf varsa yazdırır
			    {
			    	System.out.println("Class Name: " + StringProcesser.getClassName(line));
			    	singleLine.write("Class Name: "+StringProcesser.getClassName(line)+"\n");
			    	multiLine.write("Class Name: "+StringProcesser.getClassName(line)+"\n");
			    	javaDoc.write("Class Name: "+StringProcesser.getClassName(line)+"\n");
			    	
			    }
			    if(StringProcesser.isThereFunc(line)) // satırda fonksiyon varsa yazdırır
			    {
			    	
			    	printTab(brackets.getcount());
			    	System.out.println(StringProcesser.getFuncName(line));
			    	singleLine.write(StringProcesser.getFuncName(line) + "\n");
			    	multiLine.write(StringProcesser.getFuncName(line) + "\n");
			    	javaDoc.write(StringProcesser.getFuncName(line) + "\n");
			    }
			    if(line.contains("/**")&&comment.getcount()<1)   //yorum ifadeleri inceleme
			    {
			    	javaDocCommentCounter++;
			    	comment.push("/**");
			    	javaDoc.write(returnWithoutCode(line,comment));
			    }
			    else if(line.contains("/*")&&comment.getcount()<1)
			    {
			    	multilineCommentCounter++;
			    	comment.push("/*");
			    	multiLine.write(returnWithoutCode(line,comment));
			    }
			    else if (line.contains("*")&& comment.getcount() == 1)
			    {
			    	if(comment.getTop()=="/**")
			    	{
			    		javaDoc.write(returnWithoutCode(line,comment));
			    	}
			    	else
			    	{
			    		multiLine.write(returnWithoutCode(line,comment));
			    	}
			    }
			    if(line.contains("//")&&comment.getcount()<1)
			    {	
			    	singleLine.write(returnWithoutCode(line,comment));
			    	commentLineCounter++;
			    }
			    if(line.contains("*/"))
			    {
			    	comment.pull();
			    }
			    
			}
			singleLine.close();
			multiLine.close();
			javaDoc.close();
		}
	}
	
	//dosyadan bir satır döndürür
	public String getLineFromFile(int index) throws IOException
	{
		File file = new File(fileName);
		FileReader reader = new FileReader(file);
		String line ="";
		try (BufferedReader br = new BufferedReader(reader)) {
			for(int i = 0;i!=index;i++)
			{
				if((line = br.readLine()) == null)
				{
					System.out.println("Out of the range");
					break;
				}
			}
		}
		return line;
	}
	// "     " gibi boşluk yazdırı
	private void printTab(int time)
	{
		for(int i = 0;i<time;i++)
    	{
    		System.out.print("\t");
    	}
	}
	private String returnWithoutCode(String line,CommentProcesser comment)
	{
		String finalLine = "";
		if(line.contains("*/"))
		{
			for(int i = 0;i<line.indexOf("*/")+2;i++)
			{
				finalLine += String.valueOf(line.charAt(i));
			}
		}
		else 
		{
			finalLine=line;
		}
		if(line.contains("//")&&comment.getcount()==0)
		{
			finalLine = "";
			for(int i = line.indexOf("//");i<line.length();i++)
			{
				finalLine += String.valueOf(line.charAt(i));
			}
		}
		return finalLine + "\n";
	}
	
}
