Module Module1
	'Производит вывод на экран натуральные числа M и N (M<=33), и выводит все N-буквенные слова, состоящие из первых M букв русского алфавита.

	Public Const alphabet As String = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"

	Sub Main()
		Dim M, N As Long


		Console.WriteLine("Введите натуральное M<=33 : ")
		M = Console.ReadLine()

		Console.WriteLine("Введите натуральное N: ")
		N = Console.ReadLine()

		Console.WriteLine("С применением рекурсии:")

		Dim combination(N - 1) As Long
		PrepareVector(combination, M, 0)

		Console.WriteLine("Без применения рекурсии:")
		NotRecurtion(combination, M, N)
		Console.ReadLine()

	End Sub

	Public Sub PrepareVector(ByRef vector() As Long, ByVal count As Long, ByVal index As Long)
		Dim j, ind As Integer

		If index < vector.Count - 1 Then
			If vector(index) < count Then
				If vector(index + 1) = count - 1 Then
					vector(index) += 1
					For j = index + 1 To vector.Count - 1
						vector(j) = 0
					Next
				End If
				PrepareVector(vector, count, index + 1)

				vector(index) += 1
				For j = index + 1 To vector.Count - 1
					vector(j) = 0
				Next
				PrepareVector(vector, count, index)
			End If

		Else
			For ind = 0 To count - 1
				vector(vector.Length - 1) = ind
				Console.WriteLine(VectorToString(vector))
			Next
		End If

	End Sub

	Function VectorToString(ByVal vector() As Long) As String
		Dim result As String = String.Empty

		For Each letter In vector
			result += alphabet(letter)
		Next

		Return result
	End Function
	Public Sub NotRecurtion(ByRef vector() As Long, ByVal count As Long, ByVal N As Long)
		Dim i As Integer

		Do While vector(0) = 1
			For i = N To 1
				If vector(i) > count Then
					vector(i) = 0
					vector(i - 1) = vector(i - 1) + 1
				Else
					Exit For
				End If
			Next
			If vector(0) = 1 Then
				Exit Do
			End If
		Loop
		For i = 0 To count - 1
			vector(vector.Length - 1) = i
			Console.WriteLine(VectorToString(vector))
		Next
	End Sub

End Module
