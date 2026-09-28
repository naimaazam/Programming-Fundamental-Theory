| **Input**                                   | **Process**                                               | **Output**                 |
| ------------------------------------------- | --------------------------------------------------------- | -------------------------- |
| Number of guests `Guest`                        | Repeat for each guest                                     | Final price for each guest |
| Season (`Peak` / `Off-Peak`)                | Check season using nested logic                           | Hotel's total revenue      |
| Room type (`Standard` / `Deluxe` / `Suite`) | Select the appropriate rate based on season and room type |                            |
| Number of nights                            | Calculate `rate × nights`                                 |                            |
|                                             | If nights > 7, calculate **15% discount**                 |                            |
|                                             | Calculate `total price = (rate × nights) − discount`      |                            |
|                                             | Add each guest's total to `Revenue`           |                            |

