-NAIMA AZAM -26K-2504 -BS DS 1A

| **Input**                  | **Process**                                  | **Output**           |
| -------------------------- | -------------------------------------------- | -------------------- |
| Vehicle type `E/H`         | Validate all inputs                          | Vehicle type         |
| Current battery/SOC %      | Check charging station availability          | Current battery %    |
| Required charging level %  | Check whether vehicle qualifies for charging | Required charging %  |
| Parking duration           | Calculate required charging                  | Charging priority    |
| Current time               | Determine peak/off-peak                      | Peak/Off-peak status |
| Membership `Y/N`           | Assign charging priority                     | Charging cost        |
| Disabled priority `Y/N`    | Calculate charging cost                      | Parking cost         |
| Station availability `Y/N` | Calculate parking cost                       | Discount             |
|                            | Apply charging discount                      | Final payable amount |
|                            | Apply parking discount/free parking          | Warning/message      |
|                            | Calculate final amount                       |                      |
|                            | Check long-stay condition                    |                      |
