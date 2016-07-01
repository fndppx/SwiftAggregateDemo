//
//  UlityTools.swift
//  SwiftTestDemo
//
//  Created by keyan on 16/7/1.
//  Copyright © 2016年 keyan. All rights reserved.
//

import UIKit

public class UlityTools: NSObject {
    
    override init()
    {
        super.init();
    }
    
 
    class  func baseEncode(string:NSData) -> String {
        
        //        let plainData = string.dataUsingEncoding(NSUTF8StringEncoding)
        let base64String = string.base64EncodedDataWithOptions(.Encoding64CharacterLineLength)
        
        let endString :String =  String.init(data: base64String, encoding: NSASCIIStringEncoding)!
        //        let base64String = plainData?.base64EncodedStringWithOptions(.allZeros)
        return endString
    }
    class   func atomSting(parm:NSDictionary?) -> String {
        
        if parm == nil {
            return ""
        }
        
        let myKeys:NSArray = (parm?.allKeys)!
        
        let atom:NSMutableString = ""
        for key in myKeys {
            atom.appendString((key as! String)+"="+((parm?.objectForKey(key))! as! String))
        }
        
        return baseEncode(atom.dataUsingEncoding(NSUTF8StringEncoding)!)
    }
    
//    func MD5WithUrl(url:String, param:NSDictionary?) -> String {
//        
//        
//        
//    }
//    
//    func MD5(str:String) -> String {
//        
//         let  cStr = str.utf8
//        
//        
//    }
    
    
    
    

}

