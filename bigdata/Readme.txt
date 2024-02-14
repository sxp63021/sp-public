
Building Big Data Pipeline using AWS
-------------------------------------
Data Pipeline means
- collect data (either streaming or batch files/Historical)
- Data Transformation
- Load into Data Warehouse

Small example: techtter - https://www.youtube.com/watch?v=lRWkGVBb13o
- use AWS lambda to collect data from databases/file servers/API Servers
- store the data into S3
- Use Lambda/Glue/EMR to transform/enrich data in S3
- Load data into AWS Redshift (only keep the latest data, older data is in S3)
- Use AWS Quicksight to visualize the collected data

Reference Video: edureka - https://www.youtube.com/watch?v=1nhy4kMwo8E

