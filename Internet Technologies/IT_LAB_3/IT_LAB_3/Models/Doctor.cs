using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace IT_LAB_3.Models
{
    public class Doctor
    {
        [Key]
        public int Id { get; set; }
        [Required]
        public string Name { get; set; }
        [Required]
        public int HospitalId { get; set; } = 2;
        public virtual Hospital hospital { get; set; }
        public virtual ICollection<Patient> patients { get; set; }

        public Doctor()
        {
            patients = new List<Patient>();
        }
    }
}