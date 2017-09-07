# Maintenance

## Sync with github.com

### Setup hg-git

```bash
pip install mercurial hg-git
```

#### ~/.hgrc

```
[extensions]
hggit =
```

### mbed.org to github.com

```bash
hg clone https://developer.mbed.org/teams/SAKURA-Internet/code/SakuraIO/ SakuraIOmbed-sync
cd SakuraIOmbed-sync
hg push git+ssh://git@github.com:sakuraio/SakuraIOmbed.git
```

### github.com to mbed.org

```bash
hg pull git+ssh://git@github.com:sakuraio/SakuraIOmbed.git
hg outgoing https://developer.mbed.org/teams/SAKURA-Internet/code/SakuraIO/ # check diff
hg push https://developer.mbed.org/teams/SAKURA-Internet/code/SakuraIO/
```
