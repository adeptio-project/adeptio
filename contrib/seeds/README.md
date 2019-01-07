# Seeds

Utility to generate the seeds.txt list that is compiled into the client
(see [src/chainparamsseeds.h](/src/chainparamsseeds.h) and other utilities in [contrib/seeds](/contrib/seeds)).

Be sure to update `PATTERN_AGENT` in `makeseeds.py` to include the current version,
and remove old versions as necessary.

The seeds compiled into the release are created from adeptio' DNS seed data, like this (TODO: for loop):

    ping -c 1 seed0.adeptio.cc | awk 'NR==1{gsub(/\(|\)/,"",$3);print $3}' > seeds_main.txt
    ping -c 1 seed1.adeptio.cc | awk 'NR==1{gsub(/\(|\)/,"",$3);print $3}' >> seeds_main.txt
    ping -c 1 seed2.adeptio.cc | awk 'NR==1{gsub(/\(|\)/,"",$3);print $3}' >> seeds_main.txt
    ping -c 1 seed3.adeptio.cc | awk 'NR==1{gsub(/\(|\)/,"",$3);print $3}' >> seeds_main.txt
    ping -c 1 seed4.adeptio.cc | awk 'NR==1{gsub(/\(|\)/,"",$3);print $3}' >> seeds_main.txt
    ping -c 1 seed5.adeptio.cc | awk 'NR==1{gsub(/\(|\)/,"",$3);print $3}' >> seeds_main.txt
    ping -c 1 seed6.adeptio.cc | awk 'NR==1{gsub(/\(|\)/,"",$3);print $3}' >> seeds_main.txt
    ping -c 1 seed7.adeptio.cc | awk 'NR==1{gsub(/\(|\)/,"",$3);print $3}' >> seeds_main.txt
    ping -c 1 seed8.adeptio.cc | awk 'NR==1{gsub(/\(|\)/,"",$3);print $3}' >> seeds_main.txt
    ping -c 1 seed9.adeptio.cc | awk 'NR==1{gsub(/\(|\)/,"",$3);print $3}' >> seeds_main.txt
    ping -c 1 seed10.adeptio.cc | awk 'NR==1{gsub(/\(|\)/,"",$3);print $3}' >> seeds_main.txt
    ping -c 1 seed11.adeptio.cc | awk 'NR==1{gsub(/\(|\)/,"",$3);print $3}' >> seeds_main.txt

    python3 makeseeds.py < seeds_main.txt > nodes_main.txt
    python3 generate-seeds.py . > ../../src/chainparamsseeds.h

## Dependencies

Ubuntu:

    sudo apt-get install python3-dnspython
