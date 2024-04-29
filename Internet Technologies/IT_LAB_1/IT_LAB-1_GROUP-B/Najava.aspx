<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Najava.aspx.cs" Inherits="IT_LAB_1.Najava" %>
<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" runat="server">
    <div class="container">
    
      <div class="row">
        <div class="col-md-6">
           Име:
           <asp:TextBox ID="tbFullName" runat="server"></asp:TextBox>
           <asp:RequiredFieldValidator 
               class="text-danger"
               ID="RequiredFieldValidator1" 
               runat="server" 
               ErrorMessage="Внеси име"
               ControlToValidate="tbFullName">
           </asp:RequiredFieldValidator>
           
        </div>
    </div>

    <hr />


    <div class="row">
        <div class="col-md-6">
           Лозинка:
           <asp:TextBox ID="tbPassword" runat="server" TextMode="Password"></asp:TextBox>
           <asp:RequiredFieldValidator 
               class="text-danger"
               ID="PasswordFieldValidator" 
               runat="server" 
               ErrorMessage="Внеси лозинка"
               ControlToValidate="tbPassword">
           </asp:RequiredFieldValidator>
           
        
        </div>
    </div>

    <hr />

    <div class="row">
        <div class="col-md-6">
           E-адреса:
            <asp:TextBox ID="tbEmail" runat="server"></asp:TextBox>
            
            <asp:RequiredFieldValidator 
                class="text-danger"
                ID="EmailRequiredFieldValidator" 
                runat="server" 
                ErrorMessage="Невалиден форма" 
                ControlToValidate="tbEmail"></asp:RequiredFieldValidator>

            <asp:RegularExpressionValidator 
                class="text-danger"
                ID="EmailRegularExpressionValidator" 
                runat="server" 
                ErrorMessage="Невалиден формат" 
                ControlToValidate="tbEmail" 
                ValidationExpression="\w+([-+.']\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*"></asp:RegularExpressionValidator>
   
        </div>
    </div>

    <hr />

    <div class="row">
        <div class="col-md-6">
            <asp:Button ID="addInfo" runat="server" Text="Најавете се" OnClick="addInfo_Click" />
        </div>

    </div>
</div>
</asp:Content>
