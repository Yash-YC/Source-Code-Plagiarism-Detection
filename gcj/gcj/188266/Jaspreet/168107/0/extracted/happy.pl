use strict;

my @bases;
my %unhappy;
sub readFile
{
    my $cases;
    my $file = $ARGV[0];
    open(INP,$file);
    my $line=<INP>;
    chomp $line;
    $cases = $line;
    
    for(my $i=0;$i<$cases;$i++)
    {
       @bases = ();
       $line = <INP>;
       chomp $line;
       @bases = split(/ /,$line);
       findNo($i);
    }
    close(INP);
}


sub findNo
{
    my $outFile = $ARGV[1];
    open(OUT,">>$outFile");

    my $case = shift;
    my $happyNo = 2;
    for(my $i =0;$i<=$#bases;)
    {
        if(ishappy($bases[$i],$happyNo))
        {
            $i++;
        }
        else
        {
            $happyNo++;
            $i=0;
        }
    }
    $case++;
    print OUT "Case #$case: $happyNo\n";
    close(OUT);
}

                

sub ishappy
{
    my %tempHash;
    my $base = shift;
    my $no = shift;
    
    $no = convertDecimaltoBase($base,$no);
    if(exists $unhappy{$base}{$no})
    {
        return 0;
    }


    my $newNo=0;
    my $rem;
    while(1)
    {
        $newNo =0;


        while($no)
        {
            $rem = $no%10;
            $no /= 10;
            $newNo += $rem*$rem;
        }
        my $newNo = convertDecimaltoBase($base,$newNo);
        
        my $dec = $newNo;
        my $check=0;
        while($dec)
        {
            $rem = $dec%10;
            $dec /= 10;
            $check += $rem*$rem;
        }

        if($check == 1)
        {
            return 1;
        }
        else
        {
            if ((exists $tempHash{$newNo})||(exists $unhappy{$base}{$newNo}))
            {
                foreach my $key (keys %tempHash)
                {
                    $unhappy{$base}{$key} = 1;
                }
                return 0;
            }
            $tempHash{$newNo} = 1;
            
        }
        $no = $newNo;
    }
}


sub convertToDecimal
{
    my $base = shift;
    my $no = shift;
    my $multiplicand =1;
    my $decimalrep =0;
    my $rem;
    while($no)
    {
        $rem = $no%10;
        $no /= 10;
        $decimalrep += $rem*$multiplicand;
        $multiplicand = $base*$multiplicand;
    }
    return $decimalrep;
}

sub convertDecimaltoBase
{

    my $base = shift;
    my $no = shift;
    if($base ==10)
    {
        return $no;
    }
    my @digits;
    while ($no >= $base)
    {
        my $q = int($no / $base);
        my $r = $no % $base;
        $no = $q;
        push @digits,$r;
    }
    push @digits,$no;
   
    return int(join '', reverse @digits);

}



my $outFile = $ARGV[1];
open(OUT,">$outFile");
close OUT;
readFile();



        
