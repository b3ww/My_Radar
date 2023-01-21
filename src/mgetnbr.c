/*
** EPITECH PROJECT, 2022
** my
** File description:
** my_getnbr.c
*/

int take_char(char const *str, int index)
{
    int index_flag = index;
    long exp = 1;
    long nmb = 0;
    while (str[index] >= 48 && str[index] <= 57 && str[index]) {
        exp *= 10;
        index++;
    }
    exp /= 10;
    index = index_flag;
    while (str[index] >= 48 && str[index] <= 57 && str[index]) {
        nmb += (str[index] - 48) * exp;
        index++;
        exp /= 10;
    }
    (nmb > 2147483647 || nmb < -2147483648) ? nmb = 0 : 0;
    return nmb;
}

int size(char const *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

int mgetnbr(char const *str)
{
    char c;
    int sign = 1;
    for (int i = 0; i < size(str); i++) {
        c = str[i];
        if (c == '-')
            sign *= -1;
        if (c >= 48 && c <= 58)
            return (take_char(str, i) * sign);
        if (c != '+' && c != '-')
            return 0;
    }
    return 0;
}
