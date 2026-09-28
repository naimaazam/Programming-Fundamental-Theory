-NAIMA AZAM -26K-2504 -BS DS 1A

| **Input**                             | **Process**                              | **Output**                    |
| ------------------------------------- | ---------------------------------------- | ----------------------------- |
| Number of vehicles `N`                | Process vehicles one by one using a loop | Assigned zone                 |
| Vehicle type: C/B/V                   | Validate vehicle type                    | Remaining capacity            |
| User category: F/S/G                  | Validate user category                   | Rejection reason              |
| Parking permit: Y/N                   | Validate permit                          | Total vehicles processed      |
| Emergency vehicle: Y/N (if no permit) | Check parking eligibility                | Total accepted vehicles       |
|                                       | Check available capacity                 | Total rejected vehicles       |
|                                       | Assign appropriate/alternative zone      | Cars successfully parked      |
|                                       | Update zone occupancy                    | Bikes successfully parked     |
|                                       | Update car, bike, van counters           | Vans successfully parked      |
|                                       | Update rejected counter                  | Final occupancy of A, B, C    |
|                                       | Determine highest-occupancy zone         | Remaining capacity of A, B, C |
|                                       | Check whether campus is full             | Highest occupancy zone        |
|                                       |                                          | Whether entire campus is full |
