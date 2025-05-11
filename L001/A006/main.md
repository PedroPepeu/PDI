// Suponha que você deseja modificar a quantização uma imagem monocromática de 8-bits por pixel para 4-bits por pixels. Como os valores dos bytes da imagem original são mapeados para os valores quantizados? Apresente a tabela de quantização (mapeamento)

### Tabela de Quantização: 8 bits (256 tons) → 4 bits (16 tons)

| Faixa Original (8 bits) | Valor 4 bits | Valor Final (8 bits*) | Código Binário (4 bits) |
|-------------------------|--------------|-----------------------|-------------------------|
| 0 - 15                  | 0            | 8                     | 0000                    |
| 16 - 31                 | 1            | 24                    | 0001                    |
| 32 - 47                 | 2            | 40                    | 0010                    |
| 48 - 63                 | 3            | 56                    | 0011                    |
| 64 - 79                 | 4            | 72                    | 0100                    |
| 80 - 95                 | 5            | 88                    | 0101                    |
| 96 - 111                | 6            | 104                   | 0110                    |
| 112 - 127               | 7            | 120                   | 0111                    |
| 128 - 143               | 8            | 136                   | 1000                    |
| 144 - 159               | 9            | 152                   | 1001                    |
| 160 - 175               | 10           | 168                   | 1010                    |
| 176 - 191               | 11           | 184                   | 1011                    |
| 192 - 207               | 12           | 200                   | 1100                    |
| 208 - 223               | 13           | 216                   | 1101                    |
| 224 - 239               | 14           | 232                   | 1110                    |
| 240 - 255               | 15           | 248                   | 1111                    |

*Valor Final = Ponto médio da faixa (Faixa_Inferior + 8)
