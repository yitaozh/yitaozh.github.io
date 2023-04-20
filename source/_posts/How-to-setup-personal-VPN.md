---
title: How to setup personal VPN
date: 2023-04-21 04:32:58
tags: Tech
---

Most ideas and actions are from this doc [科学上网](https://github.com/haoel/haoel.github.io)

## 1. Domain

Since I am going to use gost server, it requires one domain. I purchased one domain at goDaddy.com, it costs $5 per year.

## 2. VPC related

I am using AWS LightSail, couple reasons:

1. It's cheap and first 3 months usage is free
2. It's easy to setup, like DNS related stuff

### 2.1 Create instance

I would very like to use one instance from HKG, but now LightSail is not available in HKG, so i launched one instance in NRT.

### 2.2 Assign static IP address

Under the networking tab, create one static IP address and assign it to the instance. Also, enable 443 port from outside.

### 2.3 Create domain

Under the DNS tab, create a DNS. After creation, go to goDaddy control console and change the name server to use the name servers for this DNS.

### 2.4 Gost setup

Login the instance. Git clone haoel's repo, then run the install script under /scripts folder.

## 3. Client

### 3.1 Chrome

I would recommend switchyOmega extension for Chrome, just fill in the host, the user and password then the work is done.

### 3.2 Github

To use proxy for other programs, we need to launch a gost client on the machine. It's recommended to use docker.

1. Install docker
2. Run docker for different services
    1. Shadowsocks

        ```bash
        docker run -p 1984:1984 --name gost-ss --restart=always -d ginuerzh/gost -L=ss://aes-128-gcm:password@:1984 -F 'https://user:password@host:443'
        ```

    2. Socks5 for github

        ```bash
        docker run -p 1080:1080 --name gost-socks --restart=always -d ginuerzh/gost -L=socks5://:1080 -F 'https://user:password@host:443'
        ```

        Then change the ssh config file for github access

        ```bash
        Host github.com
            Hostname github.com
            ProxyCommand nc -x localhost:1085 %h %p
        ```

### 3.3 IOS

Download Shadowrocket, and setup the proxy.
