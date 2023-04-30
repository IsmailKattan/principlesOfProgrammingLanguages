package javaFileReader;

//bu sınıfın bütün fonksiyonları static olarak yapılmıştır 
//ihtiyaca doğru bir string işlenme sınıfı
public class StringProcesser {

	public static String trimAll(String text) // bütün boşlukları çıkartırır
	{
		String sonuc="";
		for(int i = 0;i<text.length();i++)
		{
			if(text.charAt(i) == ' ')
			{
				continue;
			}
			sonuc = sonuc + String.valueOf(text.charAt(i));
		}
		
		return sonuc;
	}
	 
	 public static String getFuncName(String code) {//fonksiyon adını döndürür
		    String constructorName = null;    // fonksiyon adını tutacak bir string
		    String[] lines = code.split("\n");   
		    for (String line : lines) {
		        line = line.trim();
		        if (line.startsWith("public") && line.contains("(") && line.contains(")")) {
		            int startIndex = line.indexOf("public");
		            int endIndex = line.indexOf("(");
		            constructorName = line.substring(startIndex + 6, endIndex).trim();
		            break;
		        } else if (line.contains("new")) {
		            int index = line.indexOf("new") + 3;
		            int endIndex = line.indexOf("(");
		            constructorName = line.substring(index, endIndex).trim();
		            break;
		        }
		    }
		    return "Function Name: " + constructorName;
		}
	 
	 public static boolean isThereFunc(String code) {// fonksiyon varmı?? true veya false döndürür
		    String constructorName = null;
		    String[] lines = code.split("\n");
		    for (String line : lines) {
		        line = line.trim();
		        if (line.startsWith("public") && line.contains("(") && line.contains(")")) {
		            int startIndex = line.indexOf("public");
		            int endIndex = line.indexOf("(");
		            constructorName = line.substring(startIndex + 6, endIndex).trim();
		            break;
		        } else if (line.contains("new")) {
		            int index = line.indexOf("new") + 3;
		            int endIndex = line.indexOf("(");
		            constructorName = line.substring(index, endIndex).trim();
		            break;
		        }
		    }
		    if(constructorName == null)
		    	return false;
		    else 
		    	return true;
		}
	 
	public static String getClassName(String ex) // sınıf adı döndürür
	{
		char currentch;
		char lastch =' ';
		String currentWord = "";
		String lastWord = "";
		for(int i = 0;i< ex.length();i++)
		{
			currentch = ex.charAt(i);
			if(currentch == ' '|| currentch == '{')
			{
				if(lastch==' '|| lastch == '{')
				{
					continue;
				}
				
				if(lastWord.equals("class"))
				{
					return currentWord;
				}
				else
				{
					lastWord = currentWord;
					currentWord = "";
				}
			}
			else
			{
				currentWord = currentWord+ String.valueOf(currentch);
			}
			lastch = currentch;
		}
		return lastWord;
	}
	
	public static boolean isThereClass(String ex) // class varmı?? true veya false döndürür
	{
		char currentch;
		char lastch =' ';
		String currentWord = "";
		String lastWord = "";
		boolean isthereclass= false;
		for(int i = 0;i< ex.length();i++)
		{
			currentch = ex.charAt(i);
			if(currentch == ' ' || currentch == '{')
			{
				if(lastch==' ' || lastch == '{')
				{
					continue;
				}
				
				if(lastWord.equals("class"))
				{
					isthereclass = true;
				}
				else
				{
					lastWord = currentWord;
					currentWord = "";
				}
			}
			else
			{
				currentWord = currentWord+ String.valueOf(currentch);
			}
			lastch = currentch;
		}
		return isthereclass;
	}
}
