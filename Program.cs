using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MorseCode
{
	class Program
	{
		public class Morse
		{
			private const string[] LiteralsRus = new string[] {   "А", "Б", "В", "Г", "Д", "Е", "Ж", "З", "И",
                                                        "Й", "К", "Л", "М", "Н", "О", "П", "Р", "С", 
                                                        "Т", "У", "Ф", "Х", "Ц", "Щ", "Ы", "Ь", "Ч", 
                                                        "Ш", "Э", "Ю", "Я", "Ё" };
			private const string[] LiteralsLat = new string[] {   "A", "B", "W", "G", "D", "E", "V", 
                                                        "Z", "I", "J", "K", "L", "M", "N",
                                                        "O", "P", "R", "S", "T", "U", "F",
                                                        "H", "C", "Q", "Y", "X" };
			private const string[] LiteralCodes = new string[] {  "· –", "– · · ·", "· – –", "– – ·", 
                                                        "– · ·", "·", "· · · –", "– – · ·",
                                                        "· ·", "· – – –", "– · –", "· – · ·",
                                                        "– –", "– ·", "– – –", "· – – ·", 
                                                        "· – ·", "· · ·", "–", "· · –", 
                                                        "· · – ·", "· · · ·", "– · – ·",
                                                        "– – · –", "– · – –", "– · · –",
                                                        "– – – ·", "– – – – ", "· · – · ·",
                                                        "· · – –", "· – · –","·"};
			private const string[] Signs = new string[] { "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", 
                                                ",", "·", ";", ":", "?", "№", "\"", "'", "(", "!", "–", ")"};
			private const string[] SignCodes = new string[] { "· – – – –", "· · – – –", "· · · – –", "· · · · –",
                                                    "· · · · ·", "– · · · ·", "– – · · ·", "– – – · ·",
                                                    "– – – – ·", "– – – – –", "· – · – · –", "· · · · · ·",
                                                    "– · – · –", "– – – · · ·", "· · – – · ·", "– · · – ·", 
                                                    "· – · · – ·", "· – – – – ·", "– · – – · –", "– – · · – –",
                                                    "– · · · · –", "– · – – · –" };
			//Обычный текст
			private string plainText;
			public string PlainText
			{
				get { return plainText; }
			}

			// Текст, записанный азбукой Морзе
			private string morseText;
			public string MorseText
			{
				get { return morseText; }
			}

			public Morse(string Text)
			{
				this.plainText = Text;
			}

			// Преобразование в азбуку Морзе
			public void ConvertToMorse()
			{
				int index;
				morseText = string.Empty;
				foreach (char letter in plainText)
				{
					index = -1;
					if (letter == ' ') continue;

					//поиск символа в массиве знаков и цифр
					index = Array.IndexOf<string>(Signs, letter.ToString().ToUpper());

					//Поиск символа в массиве латинских литералов
					if (index != -1)
					{
						morseText += SignCodes[index];
						continue;
					}
					else index = Array.IndexOf<string>(LiteralsLat, letter.ToString().ToUpper());

					//Поиск символа в массиве русских литералов
					if (index != -1)
					{
						morseText += LiteralCodes[index];
						continue;
					}
					else index = Array.IndexOf<string>(LiteralsRus, letter.ToString().ToUpper());

					if (index == -1) continue;
					morseText += LiteralCodes[index];
				}
			}
		}

		static void Main(string[] args)
		{
			string str;
			Console.WriteLine("Enter a string to convert");
			str = Console.ReadLine();
			Morse morse = new Morse(str);
			morse.ConvertToMorse();
			Console.WriteLine("Convert string: {0}", morse.MorseText);
			Console.ReadLine();
		}
	}
}
