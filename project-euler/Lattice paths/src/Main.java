// Lattice paths; uses binomial theorem to calculate the amount of paths possible from the TL corner of a 20x20 grid to the bottom right corner
public class Main {
	public static void main(String[] args) { // 40 pick 20 
		int gridSize = 20;
		long paths = 1;
		for (int i = 0; i < gridSize; i++) {
		    paths *= (2 * gridSize) - i;
		    paths /= i + 1;
		}
		System.out.println(paths); // prints 137846528820

	}

}
