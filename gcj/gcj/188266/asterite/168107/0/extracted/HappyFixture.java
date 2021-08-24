import static junit.framework.Assert.assertEquals;
import static junit.framework.Assert.*;

import java.io.BufferedReader;

import org.junit.Test;

public class HappyFixture {
	
	@Test
	public void toBase2() {
		assertEquals("10", Happy.toBase(2, 2));
	}
	
	@Test
	public void toBase2_1() {
		assertEquals("11", Happy.toBase(3, 2));
	}
	
	@Test
	public void isHappy1() {
		assertTrue(Happy.isHappy(82, 10));
	}
	
	@Test
	public void isNotHappy1() {
		assertFalse(Happy.isHappy(82, 3));
	}
	
	@Test
	public void minHappy1() {
		assertEquals(3, Happy.minHappy(2, 3));
	}
	
	@Test
	public void minHappy2() {
		assertEquals(143, Happy.minHappy(2, 3, 7));
	}
	
	@Test
	public void minHappy3() {
		assertEquals(91, Happy.minHappy(9, 10));
	}
	
	@Test
	public void testInput() throws Exception {
		String result = 
			"Case #1: 3\r\n" + 
			"Case #2: 143\r\n" + 
			"Case #3: 91\r\n";
		
		assertEquals(result, Happy.minHappy("E:\\input.txt"));
	}
	
	@Test
	public void testOutput() throws Exception {
		System.out.println(Happy.minHappy("E:\\input.txt"));
	}
	
}
