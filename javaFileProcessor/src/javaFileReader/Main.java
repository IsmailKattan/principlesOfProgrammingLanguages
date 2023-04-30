package javaFileReader;

import java.io.IOException;

public class Main {

	public static void main(String[] args) throws IOException {
		JavaFileProcess file = new JavaFileProcess("Motor.java");
		file.getAllFile();

	}

}
