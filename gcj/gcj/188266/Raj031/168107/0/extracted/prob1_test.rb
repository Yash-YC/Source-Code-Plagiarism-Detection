require "test/unit"

require "prob1"

class TestProb1 < Test::Unit::TestCase
  def test_write_in_base
    assert_equal "10", write_in_base(10, 10) 
    assert_equal "1", write_in_base(1, 2) 
    assert_equal "11", write_in_base(3, 2) 
    assert_equal "23", write_in_base(13, 5) 
  end
  
  def test_write_in_10
    
    assert_equal 10, write_in_base_10("10", 10) 
    assert_equal 1, write_in_base_10("1", 2) 
    assert_equal 3, write_in_base_10("11", 2) 
    assert_equal 13, write_in_base_10("23", 5) 
  end
  
  def test_is_sum_1
    assert is_sum_one("1", 10)
    assert !is_sum_one("20", 10)
    assert is_sum_one("01", 2)
    assert is_sum_one("10", 2)
  end
  
  def test_is_happy
    assert is_happy(10, 10)
    assert is_happy(1, 10)
    assert !is_happy(2, 10)
    assert is_happy(1, 2)
    assert is_happy(2, 2)
    assert is_happy(3, 2)
    assert is_happy(82, 10)
    assert !is_happy(82, 3)
  end
  
  def test_read_file
    read_file
  end
end