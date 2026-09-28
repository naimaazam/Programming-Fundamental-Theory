-NAIMA AZAM -26K-2504 -BS DS 1A

| **Input**                        | **Process**                                              | **Output**                    |
| -------------------------------- | -------------------------------------------------------- | ----------------------------- |
| Number of students `N`           | Set `sum = 0` and `subjectFail = false` for each student | Total marks                   |
| 5 subject marks for each student | Use an inner loop to input 5 marks                       | Average                       |
|                                  | Add each mark to `sum`                                   | Student classification        |
|                                  | Check if any mark is below 33                            | `"Distinction"`               |
|                                  | Calculate average = sum / 5                              | `"Pass"`                      |
|                                  | If average ≥ 80 → Distinction                            | `"Fail"`                      |
|                                  | Else if average ≥ 60 → Pass                              | `"Fail — Subject Deficiency"` |
|                                  | Else → Fail                                              |                               |
|                                  | If any subject mark < 33, override classification        |                               |
|                                  | Repeat for all `N` students                              |                               |
