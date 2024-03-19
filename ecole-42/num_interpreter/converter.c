int match_num()
{

}

int match_len()
{

}

int    convert_nums(char *num, char **key, char **vle)
{
    int     size;
    int     index;
    int     i;
    char    cur_digit;
    char    cur_num[4];

    i = 0;
    index = 3;
    if (size % 3 != 0)
    {
        cur_num[0] = num[0];
        cur_num[1] = num[1];
        cur_num[i] = '\0';
        match_num(cur_num, key, vle);
        index += 3;
    }
    while (index < size)
    {
        while (i < index)
        {
            cur_num[0] = num[i];
            cur_num[1] = num[i + 1];
            cur_num[2] = num[i + 2];
            cur_num[j] = '\0';
            match(cur_num[0], key, vle);
            match_length(3);
            match(cur_num[1], key, vle);
        }
        i += 3;
        index += 3;
        match_len(size - i);
    }
}

int main(void)
{
    char num_arr[] = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", 
    "13", "14", "15", "16", "17", "18", "19", "20", "30", "40", "50", "60", "70", "80",
    "90", "100", "1000", "1000000", "1000000000", "1000000000000", "1000000000000000",
    "1000000000000000000", "1000000000000000000000", "1000000000000000000000000",
    "1000000000000000000000000000", "1000000000000000000000000000000",
    "1000000000000000000000000000000000", "1000000000000000000000000000000000000"];
    char word_arr[] = ["zero", "one", "two", "three", "four", "five", "six", "seven", 
    "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
    "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty",
    "fifty", "sixty", "seventy", "eighty", "ninety", "hundred", "thousand", "million",
    "billion", "trillion", "quadrillion", "quintillion", "sextillion", "septillion",
    "octillion", "nonillion", "decillion", "undecillion"];
    char num[] = "21800341";
    if (!convert_nums)
        write(1, "Error!", 6);
    return(0);
}
