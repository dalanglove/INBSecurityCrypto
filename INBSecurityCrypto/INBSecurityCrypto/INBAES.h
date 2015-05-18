//
//  INBAES.h
//  INBSecurityCrypto
//
//  Created by Daniate on 15/3/12.
//  Copyright (c) 2015年 Daniate. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonCrypto.h>
/**
 *  AES加解密。使用CBC及PKCS7Padding。
 */
@interface INBAES : NSObject
@property (nonatomic, copy, readonly) NSData *key;
@property (nonatomic, copy, readonly) NSData *iv;
+ (instancetype)sharedINBAES;
/**
 *  更新密钥。
 *
 *  kCCKeySizeAES128          = 16<br/>
 *  kCCKeySizeAES192          = 24<br/>
 *  kCCKeySizeAES256          = 32<br/>
 *
 *  keySize必须为上面中的某个，单位字节。
 */
- (void)updateKeyWithKeySize:(unsigned int)keySize;
/**
 *  更新初始化向量。IV大小为kCCBlockSizeAES128（16）字节。
 */
- (void)updateIV;
/**
 *  AES-128 加密
 *
 *  @param plainData 待加密数据（明文数据）
 *
 *  @return 加密后的数据（密文数据）
 */
- (NSData *)AES128Encrypt:(NSData *)plainData;
/**
 *  AES-128 解密
 *
 *  @param cipherData 待解密数据（密文数据）
 *
 *  @return 解密后的数据（明文数据）
 */
- (NSData *)AES128Decrypt:(NSData *)cipherData;
/**
 *  AES-192 加密
 *
 *  @param plainData 待加密数据（明文数据）
 *
 *  @return 加密后的数据（密文数据）
 */
- (NSData *)AES192Encrypt:(NSData *)plainData;
/**
 *  AES-192 解密
 *
 *  @param cipherData 待解密数据（密文数据）
 *
 *  @return 解密后的数据（明文数据）
 */
- (NSData *)AES192Decrypt:(NSData *)cipherData;
/**
 *  AES-256 加密
 *
 *  @param plainData 待加密数据（明文数据）
 *
 *  @return 加密后的数据（密文数据）
 */
- (NSData *)AES256Encrypt:(NSData *)plainData;
/**
 *  AES-256 解密
 *
 *  @param cipherData 待解密数据（密文数据）
 *
 *  @return 解密后的数据（明文数据）
 */
- (NSData *)AES256Decrypt:(NSData *)cipherData;
/**
 *  加解密。当需要使用指定的密钥或初始化向量时，可以使用该方法。会修改_key、_iv。
 *
 *  @param data      明文/密文
 *  @param key       密钥
 *  @param iv        初始化向量，可以为空
 *  @param operation kCCEncrypt/kCCDecrypt
 *
 *  @return 加密/解密后的数据
 */
- (NSData *)doCipher:(NSData *)data
				 key:(NSData *)key
				  iv:(NSData *)iv
		   operation:(CCOperation)operation;
@end