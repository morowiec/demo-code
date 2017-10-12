<?php
/**
 * Created by PhpStorm.
 * User: wgrzeszkiewicz
 * Date: 04.03.16
 * Time: 14:11
 */
 
/**
 * Class NumberInWords
 * @package Master\Bundle\CoreBundle\Tools
 *
 * Wzorowane na:
 * @see http://4programmers.net/PHP/FAQ/Jak_zamieni%C4%87_liczb%C4%99_na_jej_posta%C4%87_s%C5%82own%C4%85_
 */
class NumberInWords
{
    /**
     * @var array
     */
    protected static $words = array('minus',
        array('zero', 'jeden', 'dwa', 'trzy', 'cztery', 'pięć', 'sześć', 'siedem', 'osiem', 'dziewięć'),
        array('dziesięć', 'jedenaście', 'dwanaście', 'trzynaście', 'czternaście', 'piętnaście', 'szesnaście', 'siedemnaście', 'osiemnaście', 'dziewiętnaście'),
        array('dziesięć', 'dwadzieścia', 'trzydzieści', 'czterdzieści', 'pięćdziesiąt', 'sześćdziesiąt', 'siedemdziesiąt', 'osiemdziesiąt', 'dziewięćdziesiąt'),
        array('sto', 'dwieście', 'trzysta', 'czterysta', 'pięćset', 'sześćset', 'siedemset', 'osiemset', 'dziewięćset'),
        array('tysiąc', 'tysiące', 'tysięcy'),
        array('milion', 'miliony', 'milionów'),
        array('miliard', 'miliardy', 'miliardów'),
        array('bilion', 'biliony', 'bilionów'),
        array('biliard', 'biliardy', 'biliardów'),
        array('trylion', 'tryliony', 'trylionów'),
        array('tryliard', 'tryliardy', 'tryliardów'),
        array('kwadrylion', 'kwadryliony', 'kwadrylionów'),
        array('kwintylion', 'kwintyliony', 'kwintylionów'),
        array('sekstylion', 'sekstyliony', 'sekstylionów'),
        array('septylion', 'septyliony', 'septylionów'),
        array('oktylion', 'oktyliony', 'oktylionów'),
        array('nonylion', 'nonyliony', 'nonylionów'),
        array('decylion', 'decyliony', 'decylionów'),
    );
 
    /**
     * Podaje słowną wartość liczby całkowitej (równierz podaną w postaci stringa)
     *
     * @param integer $int
     * @return string
     */
    public static function integerNumberToWords($int)
    {
        $int = strval($int);
        $in = preg_replace('/[^-\d]+/', '', $int);
 
        $return = '';
 
        if ($in{0} == '-') {
            $in = substr($in, 1);
            $return = self::$words[0] . ' ';
        }
 
        $txt = str_split(strrev($in), 3);
 
        if ($in == 0) {
            $return = self::$words[1][0] . ' ';
        }
 
        for ($i = count($txt) - 1; $i >= 0; $i--) {
            $number = (int) strrev($txt[$i]);
 
            if ($number > 0) {
                if ($i == 0) {
                    $return .= self::number($number) . ' ';
                } else {
                    $return .= ($number > 1 ? self::number($number) . ' ' : '')
                            . self::inflection(self::$words[4 + $i], $number) . ' ';
                }
            }
        }
 
        return self::clear($return);
    }
 
    /**
     * Podaje słowną wartość kwoty wraz z wartościami po kropce.
     * Nie przyjmuje wartości przedzielonych przecinkami (jako wartości nie numerycznych).
     *
     * @param integer|string $amount
     * @param string $currencyName
     * @param string $centName
     * @return string
     * @throws \Exception
     */
    public static function amountToWords($amount, $currencyName = 'zł', $centName = 'gr')
    {
        if (!is_numeric($amount)) {
            throw new \Exception('Nieprawidłowa kwota');
        }
 
        $amountString = number_format($amount, 2, '.', '');
        list($bigAmount, $smallAmount) = explode('.', $amountString);
 
        $bigAmount = static::integerNumberToWords($bigAmount) . ' ' . $currencyName . ' ';
        $smallAmount = static::integerNumberToWords($smallAmount) . ' ' . $centName;
 
        return self::clear($bigAmount . $smallAmount);
    }
 
    /**
     * Czyści podwójne spacje i trimuje
     *
     * @param $string
     * @return mixed
     */
    protected static function clear($string)
    {
        return preg_replace('!\s+!', ' ', trim($string));
    }
 
    /**
     * $inflections = Array('jeden','dwa','pięć')
     *
     * @param string[] $inflections
     * @param $int
     * @return mixed
     */
    protected static function inflection(array $inflections, $int)
    {
        $txt = $inflections[2];
 
        if ($int == 1) {
            $txt = $inflections[0];
        }
 
        $units = intval(substr($int, -1));
 
        $rest = $int % 100;
 
        if (($units > 1 && $units < 5) &! ($rest > 10 && $rest < 20)) {
            $txt = $inflections[1];
        }
 
        return $txt;
    }
 
    /**
     * Odmiana dla liczb < 1000
     *
     * @param integer $int
     * @return string
     */
    protected static function number($int)
    {
        $return = '';
 
        $j = abs(intval($int));
 
        if ($j == 0) {
            return self::$words[1][0];
        }
 
        $units = $j % 10;
        $dozens = intval(($j % 100 - $units) / 10);
        $hundreds = intval(($j - $dozens * 10 - $units) / 100);
 
        if ($hundreds > 0) {
            $return .= self::$words[4][$hundreds - 1] . ' ';
        }
 
        if ($dozens > 0) {
            if ($dozens == 1) {
                $return .= self::$words[2][$units] . ' ';
            } else {
                $return .= self::$words[3][$dozens - 1] . ' ';
            }
        }
 
        if ($units > 0 && $dozens != 1) {
            $return .= self::$words[1][$units] . ' ';
        }
 
        return $return;
    }
}
