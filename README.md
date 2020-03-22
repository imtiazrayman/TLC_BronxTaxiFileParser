# TLC_BronxTaxiFileParser

This is a parser which parsers approximately 1,400,000 trips in the Bronx. 
The file parser takes a CSV, which contains all of the Bronx taxi trips from the TLC and computes the number of trips made from a certain location to another location. The locations are labeled as Pickup Locations and Drop Off Locations 
which are numbers that correspond to a particular area in the Bronx.

There are three versions of the Parser, 
(Single processes (Single Thread) Version #1) parser.c.
(Multi processes (Single Thread) Version #2) parserVersion2.c
