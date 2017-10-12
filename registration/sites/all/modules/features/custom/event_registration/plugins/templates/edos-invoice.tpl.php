<?php
/**
 * @file
 * EPSO Link template file.
 *
 * @ingroup views_templates
 */
?>

<table style="width: 100%; border: none; border-collapse: collapse; font-size: 9pt">
    <tbody style="border: none;">
        <tr>
            <td>
                <table style="width: 100%; border: none;">
                    <tbody style="border: none;">
                        <tr>
                            <td>
                                <p><strong>DOS-ELTEA s.c. M. Rosińska-Trim, G. Śpiewak</strong></p>
                                <p>ul. Grochowska 341/120<br />
                                    03-822 Warszawa<br />
                                    NIP: 113-285-76-95<br />
                                    REGON: 146235023<br />
                                    tel. 601 800 991</p> 
                            </td>
                            <td style="text-align: right;">
                                <img src="http://e-dos.org/sites/edos/files/invoice-logo.png" />

                            </td>
                        </tr>
                    </tbody>
                </table>          
            </td>
        </tr>
        <tr>
            <td>
                <table style="width: 100%; border: none; text-align: right;">
                    <tbody style="border: none;">
                        <tr>
                            <td style="width: 70%">
                                Miejsce wystawienia:<br />
                                Data sprzedaży:<br />
                                Data wystawienia:<br />
                            </td>
                            <td>
                                Warszawa<br /> 
                                <?php print date('Y-m-d'); ?><br /> 
                                <?php print date('Y-m-d'); ?><br />
                            </td>
                        </tr>
                    </tbody>
                </table>          
            </td>
        </tr>    
        <tr>
            <td style="text-align: center; font-size: 1.5em; font-weight: bold; padding: 10pt">FAKTURA <?php print $data['number']; ?></td>
        </tr>    
        <tr>
            <td style="text-align: center; font-size: 1.2em; font-weight: bold; padding: 10pt">Oryginał /	Kopia</td>
        </tr>    
        <tr>


            <td>
                <table style="width: 100%; border: none; text-align: left;">
                    <tbody style="border: none;">
                        <tr>
                            <td style="width: 50%">
                                <p>Sprzedawca:</p>
                                <p><strong>DOS-ELTEA s.c. M. Rosińska-Trim, G. Śpiewak</strong></p>
                                <p>ul. Grochowska 341/120<br />
                                    03-822 Warszawa<br />
                                    NIP: 113-285-76-95</p>
                            </td>
                            <td>
                                <p>Nabywca:</p>
                                <p><strong><?php print $data['billing']['name_line']; ?></strong></p>
                                <p><?php print $data['billing']['thoroughfare']; ?><br /> 
                                    <?php print $data['billing']['postal_code']; ?> <?php print $data['billing']['locality']; ?><br />
                                    NIP: <?php print $data['billing']['tax_number']; ?><p>
                            </td>
                        </tr>
                    </tbody>
                </table>          
            </td>
        </tr>    
        <tr>
            <td>
                <table style="width: 100%; border: none; text-align: left;">
                    <tbody style="border: none;">
                        <tr>
                            <td style="width: 50%">
                                <p>Sposób płatności: <strong>przelew</strong><br />
                                    Bank: <strong>mBank</strong><br />
                                    Nr konta: <strong>27 1140 2004 0000 3502 7436 0543</strong>
                                </p>
                            </td>
                            <td>
                                <p>Termin płatności:</p>
                                <?php print ($data['status'] == 'completed') ? date('Y-m-d') : '7 dni  '; ?><br /> 

                            </td>
                        </tr>
                    </tbody>
                </table>          
            </td>
        </tr>    
        <tr>
            <td>
                <table style="width: 100%; text-align: left;">
                    <tbody style="border: none;">
                        <tr style="background: #bbbbbb">
                            <th style="border: 1px solid #000000; padding: 3px; color: #000000;">Lp.</th>
                            <th style="border: 1px solid #000000; padding: 3px; color: #000000;">Nazwa usługi</th>
                            <th style="border: 1px solid #000000; padding: 3px; color: #000000;">Ilość</th>
                            <th style="border: 1px solid #000000; padding: 3px; color: #000000;">Jm</th>
                            <th style="border: 1px solid #000000; padding: 3px; color: #000000;">Cena jednost.</th>
                            <th style="border: 1px solid #000000; padding: 3px; color: #000000;">Wartość brutto</th>
                        </tr>
                        <?php foreach ($data['rows'] as $row_id => $row): ?>

                          <tr>
                              <td style="border: 1px solid #000000;"><?php print $row_id + 1; ?></td>
                              <td style="border: 1px solid #000000;"><?php print $row['title']; ?></td>
                              <td style="border: 1px solid #000000;"><?php print $row['qty']; ?></td>
                              <td style="border: 1px solid #000000;"><?php print $row['uom']; ?></td>
                              <td style="border: 1px solid #000000;"><?php print $row['price']; ?> PLN</td>
                              <td style="border: 1px solid #000000;"><?php print $row['qty'] * $row['price']; ?> PLN</td>
                          </tr>          
                        <?php endforeach; ?>          
                        <?php $data['rows'] ?>
                        <tr>
                            <td colspan="4"></td>
                            <td style="border: 1px solid #000000;">Razem:</td>
                            <td style="border: 1px solid #000000;"><?php print $data['total']; ?> PLN</td>
                        </tr>      
                    </tbody>
                </table>
            </td>
        </tr>    
        <tr>		 		
            <td>
                <table style="width: 100%; border: none; text-align: left;">
                    <tbody style="border: none;">
                        <tr>
                            <td style="width: 50%">
                                <p>Razem do zapłaty: <?php print $data['total']; ?> PLN	- <?php print ($data['status'] == 'completed') ? 'ZAPŁACONO' : 'ZAPŁACONO 0.00 PLN'; ?></p>
                            </td>
                            <td>
                                <p>Słownie: <?php print NumberInWords::integerNumberToWords($data['total']); ?> PLN 00/100</p>
                            </td>
                        </tr>
                    </tbody>
                </table>          
            </td>
        </tr> 
        <tr>
            <td>Osoba upoważniona do wystawienia rachunku: Grzegorz Śpiewak</td>
        </tr>  
    </tbody>
</table>
