#!/usr/bin/env/ lua

while true do
    input = io.read("*number")
    if input == 42 then
        break;
    end
    print (input)
end
