import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class Main
{
	public static void main(String[] args) throws Exception
	{
		FileReader fin = new FileReader("A-small-attempt0.in");
		BufferedReader reader = new BufferedReader(fin);

		int cases = Integer.parseInt(reader.readLine());

		for (int caseNo = 1; caseNo <= cases; ++caseNo)
		{
			// System.err.println("Processing case #" + caseNo);

			int decimalResult = solveProblem(reader.readLine());

			System.out.println("Case #" + caseNo + ": " + decimalResult);
		}
	}

	private static int solveProblem(String line)
	{
		String[] baseStrings = line.split(" ");
		int[] bases = new int[baseStrings.length];

		// prepare usable base
		for (int baseIndex = 0; baseIndex < baseStrings.length; ++baseIndex)
		{
			bases[baseIndex] = Integer.parseInt(baseStrings[baseIndex]);
		}

		return calculateHappyInBases(bases);
	}

	private static int calculateHappyInBases(int[] bases)
	{
		// start the number must be 2
		int testNumber = 2;

		for (int i = 0; i < bases.length; ++i)
		{
			boolean happy = isThisNumberHappyInBase(testNumber, bases[i]);

			// not happy, go on
			if (!happy)
			{
				++testNumber;
				i = -1;
			}
		}

		return testNumber;
	}

	private static Map<Integer, Set<Integer>[]> happyMap = new HashMap<Integer, Set<Integer>[]>();

	private static boolean isThisNumberHappyInBase(int testNumber, int base)
	{
		Set<Integer>[] result = happyMap.get(base);
		Set<Integer> happy = null;
		Set<Integer> notHappy = null;

		if (result != null)
		{
			happy = result[0];
			notHappy = result[1];

			if (happy.contains(testNumber))
				return true;

			if (notHappy.contains(testNumber))
				return false;
		}

		int[] numbersInRadix = decimalToRadix(testNumber, base);

		Set<Integer> badSum = new HashSet<Integer>();

		boolean happyStatus;

		while (true)
		{
			int[] squares = new int[numbersInRadix.length];

			for (int i = 0; i < squares.length; ++i)
			{
				squares[i] = numbersInRadix[i] * numbersInRadix[i];
			}

			int sum = 0;

			// System.err.print("square:");
			for (int i = 0; i < squares.length; ++i)
			{
				// System.err.print(squares[i] + "*" + squares[i] + " + ");

				sum += squares[i];
			}
			// System.err.println(" = " + sum);

			if (sum == 1)
			{
				happyStatus = true;
				break;
			}

			if (badSum.contains(sum))
			{
				happyStatus = false;
				break;
			}

			badSum.add(sum);
			numbersInRadix = decimalToRadix(sum, base);
		}

		if (result == null)
		{
			happy = new HashSet<Integer>();
			notHappy = new HashSet<Integer>();

			happyMap.put(base, new Set[] { happy, notHappy });
		}

		if (happyStatus)
		{
			happy.add(testNumber);
		} else
		{
			notHappy.add(testNumber);
		}

		return happyStatus;
	}

	private static int[] decimalToRadix(int testNumber, int base)
	{
		// System.err.println("decimalToRadix(" + testNumber + ", " + base +
		// ")");
		List<Integer> numbers = new ArrayList<Integer>();

		while (true)
		{
			int number = testNumber % base;
			int remain = testNumber / base;

			numbers.add(number);

			if (remain == 0)
			{
				Collections.reverse(numbers);
				break;
			}

			testNumber = remain;
		}

		int[] result = new int[numbers.size()];

		// System.err.print("decimalToRadix:");
		for (int i = 0; i < numbers.size(); ++i)
		{
			result[i] = numbers.get(i);
			// System.err.print(result[i]);
			// System.err.print(' ');
		}
		// System.err.println();

		return result;
	}
}
